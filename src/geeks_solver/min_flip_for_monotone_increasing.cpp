#include<min_flip_for_monotone_increasing.h>
#include<iostream>
#include<vector>
#include<algorithm>
//dp to choose from making solution with increading zero's and increasing one's
// solution d(i) = min{ d1(i -1) , d0(i -1) }

int min_flip_monotone_increasing( const std::string& input_string )
{
    int n_size = input_string.size();
    std::vector<int> dp0;
    dp0.reserve(n_size);
    std::vector<int> dp1;
    dp1.reserve(n_size);
    if(input_string[0] == '0') {
        dp1[0] = 1;
        dp0[0] = 0;
    }
    else {
        dp1[0] = 0;
        dp0[0] = 1;
    }
    
    for(int n_idx= 1; n_idx< n_size; ++n_idx)
    {
        if(input_string[n_idx] == '0') {
            dp0[ n_idx ] = dp0[n_idx -1];
            dp1[ n_idx ] = std::min( dp0[n_idx -1] + 1,  dp1[n_idx -1] + 1);
        }
        else {
            dp0[ n_idx ] = dp0[ n_idx -1 ] + 1;
            dp1[ n_idx ] = std::min( dp1[ n_idx -1], dp0[ n_idx -1]  ); 
        }
    } 
    return (std::min( dp1[ n_size -1], dp0[ n_size -1] ) );
}
