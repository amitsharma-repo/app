#include<iostream>
#include<pair_with_sum_from_two_subarray.h>
#include<algorithm>
#include<functional>
std::vector<std::pair<int,int>> find_pair_with_sum( std::vector<int>& first_array, std::vector<int>& second_array )
{
    std::vector< std::pair< int, int> > vec_result;
    std::sort( first_array.begin(), first_array.end() );
    std::sort( second_array.begin(), second_array.end() );
    int i = 0;
    int j = second_array.size() -1;
    for( ; i < first_array.size() && j > 0; )
    {
        i++;
        j--;
    }
}
