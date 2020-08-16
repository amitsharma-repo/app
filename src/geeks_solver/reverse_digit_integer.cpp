#include<reverse_digit_integer.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int get_reverse_digit_of_integer( int n_value )
{
    std::cout << "value of integer is " << n_value << std::endl;
    bool b_sign = true;
    if( n_value < 0 ) {
       n_value = -n_value; 
       b_sign = false;
    }
    long long n_return_value = 0;
    while( n_value != 0 ) {
        int digit = n_value%10;
        if( n_return_value* 10 > INT_MAX && b_sign) {
            return 0;
        }
        if( n_return_value*10 > INT_MAX && !b_sign ) {
            return 0;
        } 
        n_return_value = n_return_value* 10 + digit;
        std::cout << n_return_value << std::endl;
        n_value= n_value/10;
    }
    if( b_sign )
        return n_return_value;
    else
        return -n_return_value;
}
