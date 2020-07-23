#include <iterator>
#include<jumping_number.h>
#include<queue>
#include<cmath>
std::vector<int> find_jumping_number_list( int n_input )
{
    std::vector<int> vec_result;
    std::queue<int> generator_queue;
    vec_result.push_back(0);
    for( int i = 1; i<= 9 && i < n_input ; ++i ) {
        generator_queue.push( i );
        vec_result.push_back( i );
    }
    bool bflag = false;
    for( int i= 0; bflag == false; ++i)
    {
        std::queue<int> temp_queue;
        while( !generator_queue.empty() ) {
            int num = generator_queue.front();
        
            generator_queue.pop();
            int n_rem = num% 10;
            int new_num;
            if( n_rem != 0 ) {
                new_num = num* 10+ n_rem - 1;
                if( new_num > n_input ) {
                    bflag = true;
                    break;
                }
                vec_result.push_back( new_num );
                temp_queue.push( new_num );
            }
            if( n_rem != 9 ) {
                new_num = num* 10+ n_rem + 1;
                if( new_num > n_input ) {
                    bflag = true;
                    break;
                }
                vec_result.push_back( new_num );
                temp_queue.push( new_num );            
            }

        }
        generator_queue = temp_queue;
    }
    return vec_result;
}
