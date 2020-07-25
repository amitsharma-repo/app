#include<triplet_with_zero_sum.h>
#include<algorithm>
#include<unordered_set>
bool find_triptet_with_zero_sum( const std::vector<int>& vec_input )
{
    bool b_found = false;
    std::unordered_set<int> hash_value;
    std::for_each( vec_input.begin(), vec_input.end(), [&hash_value](int x){
            hash_value.insert(x);
           } );
    for( int i_idx =0; i_idx < vec_input.size() && !b_found ; ++i_idx ) {
        for( int j_idx =0; j_idx < vec_input.size(); ++j_idx ) {
            if ( j_idx == i_idx )
                continue;
            int sum = - ( vec_input[ i_idx ] + vec_input[ j_idx ] );
            if( hash_value.find( sum ) != hash_value.end() ) {
                b_found = true;
                break;
            }  
        }

    }
    return b_found;
}

