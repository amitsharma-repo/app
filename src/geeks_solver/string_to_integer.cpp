#include <limits>
#include <cstdint>
#include<string_to_integer.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int my_atoi( const std::string& str_value )
{
    long long n_result_int = 0;
    int b_signed   = false;
    std::string str_int_value= str_value;
    int n_length= str_int_value.size();
    int cnt = 0;
    while(str_int_value[cnt++] == ' ' && cnt < n_length);
    for( int n_idx = cnt - 1; n_idx< n_length; ++n_idx ) {
        char ch= str_int_value[n_idx];
        if( n_idx == cnt - 1 && ch == 45 ) {
            b_signed = true;
            continue;
        }
        else if ( n_idx == cnt -1 && ch == 43 ) {
            b_signed = false;
            continue;
        }
        if( ch< 48 || ch> 57 ) {
            break;
        }
        n_result_int= n_result_int*10 + ( ch - 48 );
        if( n_result_int > INT_MAX )
            return b_signed ? INT_MIN : INT_MAX;
    }
    if( b_signed )
        return -n_result_int;
    else
        return n_result_int;
}
