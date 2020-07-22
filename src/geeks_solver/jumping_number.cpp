#include <iterator>
#include<jumping_number.h>
#include<queue>
#include<cmath>
std::vector<int> find_jumping_number_list( int n_input )
{
    std::vector<int> vec_result;
    std::queue<int> generator_queue;
    vec_result.push_back(0);
    for( int i = 1; i< 9; ++i ) {
        generator_queue.push( i );
    }
    for( int i= 0; i< n_input; ++i)
    {
        std::queue<int> temp_queue;
        while( !generator_queue.empty() ) {
            int num = generator_queue.front();
            vec_result.push_back( num );
            generator_queue.pop();
            int n_pow = pow( 10, i );
            int n_rem = num% 10;
            int new_num;
            if( n_rem != 9 ) {
                new_num = num*n_pow + n_rem + 1;
                temp_queue.push( new_num );
            }
            if( n_rem != 0 ) {
                new_num = num*n_pow + n_rem - 1;
                temp_queue.push( new_num );            
            }

        }
        generator_queue = temp_queue;
    }
    for( int n_cnt= 0; n_cnt= generator_queue.size(); ++n_cnt ) {
        vec_result.push_back(generator_queue.front());
        generator_queue.pop();
    }
    return vec_result;
}
