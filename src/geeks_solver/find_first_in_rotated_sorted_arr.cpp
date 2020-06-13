#include <find_first_in_rotated_sorted_arr.h>

int recurse_to_find_start_idx( int* arr, int n_start, int n_end )
{
    int n_return_idx = -1;
   //array is already sorted
    if(n_start == n_end)
        return -1;
   int n_mid =   n_start + (n_end - n_start)/2;
   if( arr[n_mid] > arr[n_mid + 1] )
       return n_mid + 1;
   if( n_mid != n_start && arr[ n_mid ] < arr[ n_mid -1 ] )
        return n_mid;

    if( arr[ n_start ] > arr[ n_mid ] )
        n_return_idx = recurse_to_find_start_idx( arr, n_start, n_mid );
    else
        n_return_idx = recurse_to_find_start_idx( arr, n_mid + 1 , n_end );

    return n_return_idx;
    
}
int find_first_in_rotated_sorted_array( int* arr, int nSize )
{
    int n_start = 0;
    int n_end = nSize - 1;    
    return  recurse_to_find_start_idx( arr, n_start, n_end );
}

