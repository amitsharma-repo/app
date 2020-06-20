#include<find_duplicate_in_n_time.h>
#include<iostream>
std::vector<int> find_duplicate_in_n_time( int n_size, int* p_arr )
{
    std::vector<int> vec_result;
    for(int n_index = 0 ; n_index < n_size; ++n_index)
    {
        if( p_arr[ abs(p_arr[ n_index ] )] < 0 )
            vec_result.push_back(abs(p_arr[n_index] ));
        else
            p_arr[ abs(p_arr[ n_index ] )] = -p_arr[ abs(p_arr[ n_index ] )];
    }
    return vec_result;
}
