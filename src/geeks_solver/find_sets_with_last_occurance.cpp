#include <find_sets_with_last_occurance.h>
std::vector<int> find_sets_with_last_occurance( std::vector< char> vec_occurance )
{
    std::vector<int> vec_result;
    std::vector<int> vec_start;
    vec_start.reserve(26);
    std::vector<int> vec_end;
    vec_end.reserve(26);
    int n_idx = 0;
    while( n_idx < vec_occurance.size() )
    {
        vec_end[ vec_occurance[ n_idx] -97 ] = n_idx; 
        n_idx++;
    }    
    int n_max = vec_end[vec_occurance[ 0 ] - 97];
    int n_start = 0;
    int n_nxt = 1; 
    while( n_nxt < vec_occurance.size() )
    {
        while( n_nxt < n_max )
        {
            if( vec_end[ vec_occurance[ n_nxt ] -97 ] > n_max ) {
                n_max = vec_end[ vec_occurance[ n_nxt ] -97 ]; 
            }
            n_nxt++;        
        }
        vec_result.push_back( n_max - n_start);
        n_start = n_nxt + 1;
        n_max = vec_end[ vec_occurance [ n_start ] -97 ];
        n_nxt ++;
    }
}
