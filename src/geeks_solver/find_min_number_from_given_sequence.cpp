#include <find_min_number_from_given_sequence.h>
//find minimum positive element missing in the unsorted array with positive and  
//negative elements
//arr [ 4, -2, 5, 2, 10, -7, -6, 1]
//output : 3 
//time complexity: ( n );
//space complexity: ( 1 );
int find_min_number_from_given_sequence( int n_size, int* p_arr )
{
    int n_left_idx = 0;
    int n_right_idx = n_size -1;
    while( n_right_idx != n_left_idx)
    {
        while( p_arr[ n_left_idx ] > 0 && n_right_idx - n_left_idx > 0) n_left_idx++;
        while( p_arr[ n_right_idx ] < 0 && n_right_idx - n_left_idx  > 0) n_right_idx--;
        if( n_right_idx != n_left_idx )
        {
            //swap elements
            int temp = p_arr[ n_left_idx ];
            p_arr[ n_left_idx ] = p_arr[ n_right_idx ];
            p_arr[ n_right_idx ] = temp;

        }
    }
    //for( int n_index = 0 ; n_index < n_size; ++n_index )
  //     std::cout << "values after shifting negative" << p_arr[ n_index ] << std::endl;
    int n_start = 0;
    int n_end = n_left_idx ;
    for( int n_cnt = n_start; n_cnt < n_end ; ++n_cnt) {
        if( p_arr[ abs( p_arr[ n_cnt ] ) -1 ] > 0 ) {
            p_arr[ abs( p_arr[ n_cnt ] ) -1 ] = -p_arr[ abs( p_arr[ n_cnt ] ) -1 ];
        }
    }
    int res_min = -1;
    while( n_start <= n_end )
    {
        if( p_arr[ n_start ] > 0) {
            res_min = n_start;
            break;
        } n_start++;
    }

   // for( int n_index = 0 ; n_index < n_size; ++n_index )
    //   std::cout << "values after hashing" << p_arr[ n_index ] << std::endl;
    return res_min + 1; 
}



