#include <find_subarray_with_given_sum.h>
#include <algorithm>
#include <tuple>
std::tuple<int, int> find_subarray_with_given_sum(std::vector<int> vec_input, int n_sum)
{
    int n_start_idx = 0;
    int n_end_idx = 0;
    int n_temp_sum = vec_input[ n_start_idx ];
    bool b_found = false;

    while( n_end_idx < vec_input.size() - 1 ) {
        if( n_temp_sum == n_sum ) {
            b_found = true;
            break;
        }
        if( n_start_idx == n_end_idx || n_temp_sum < n_sum ) {
            n_end_idx++;     
            n_temp_sum += vec_input[ n_end_idx ];
        }
        else {
            n_temp_sum-= n_start_idx;
            n_start_idx--;
        }
    }
    
    if( b_found )
        return std::make_tuple(n_start_idx, n_end_idx ); 
    else
        return std::make_tuple( -1 ,-1 );
      
}
