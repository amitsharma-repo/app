#include<partition_array_into_disjoint_interval.h>
int find_partition_array_into_disjoint_interval( std::vector< int >& input_data )
{
    int n_min_right_val = input_data[ input_data.size() -1 ]; 
    int n_max_left_val = input_data[ 0 ]; 
    int n_left_idx = 0;
    int n_right_idx = input_data.size() - 1;
    //switch movement from left to right based on:
    //left switch: any max element in left need to be verified by existance smaller value which is min value in right
    //right switch: any min element in right need to be verified by existance of greter value which in max value in left
    bool b_direction = false; 
     
    while( n_right_idx >= n_left_idx + 1)   {
        /*if( n_max_left_val < n_min_right_val )
            b_direction = true;
        else
            b_direction = false;   
        */
        switch( b_direction )
        {
            case true:
                while( n_min_right_val > input_data[ n_left_idx ] ) {
                    if(n_max_left_val < input_data[ n_left_idx ] )
                        n_max_left_val = input_data[ n_left_idx ];
                    n_left_idx++;
                }
                b_direction = false;
            case false:
                while( n_max_left_val < input_data[ n_right_idx ] )  {
                    if( n_min_right_val > input_data[ n_right_idx] )
                        n_min_right_val = input_data[ n_right_idx ];
                    n_right_idx--;
                }
                b_direction = true;
        }
    }     
    return n_left_idx;
}
