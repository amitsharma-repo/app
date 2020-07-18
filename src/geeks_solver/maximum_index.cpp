#include<maximum_index.h>
#include<iostream>
int find_max_index(std::vector<int> vec_input)
{
    int n_start_idx = 0;
    int n_end_idx = vec_input.size() - 1;
    int n_start = vec_input[n_start_idx];
    int n_end = vec_input[n_end_idx];
    int result = 0;
    while( n_start_idx < n_end_idx ) {
        if( vec_input[n_end_idx] >= vec_input[n_start_idx] )
            break;
        n_end_idx--;
    }
    n_start_idx = n_start_idx + 1;
    result = n_end_idx;
    while(n_start_idx + result < vec_input.size()) {
        n_end_idx = n_start_idx + result;
        for( int idx = vec_input.size() -1; idx > n_end_idx; --idx) {
            if( vec_input[idx] >= vec_input[n_start_idx] ) {
                if( result < idx - n_start_idx )
                    result = idx - n_start_idx;
                break;
            }
                
        }
        n_start_idx++;
    }
    return result;
}
