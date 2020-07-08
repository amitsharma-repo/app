#include<count_way_to_reach_n_stair.h>

int count_way_to_reach_stairs(int n_stair_cnt)
{
    if( n_stair_cnt == 0 )
        return 0;
    if( n_stair_cnt == 1)
        return 1;
    int* n_way_size = new int[n_stair_cnt + 1];
    n_way_size[0] = 1; 
    n_way_size[1] = 1;
    for(int n_stair = 2 ; n_stair <= n_stair_cnt; ++n_stair )
    {
        n_way_size[n_stair]   = n_way_size [ n_stair -1 ] + n_way_size [n_stair -2 ];
    }
    return n_way_size[ n_stair_cnt];
}
