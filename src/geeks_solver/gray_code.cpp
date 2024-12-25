#include "gray_code.h"
std::vector<int> grayCode(int n) {
    std::vector<int> vec_GrayCode(pow(2, n), 0);
    vec_GrayCode[0] = 0;
    vec_GrayCode[1] = 1;
    for ( int i = 2; i <= n; ++i)
    {
        int nCnt = pow(2, i);
        int nBackIdx = (nCnt)/2 - 1;
        for ( int idx = (nCnt)/2; idx < nCnt ; idx++)
        {
            vec_GrayCode[idx] = pow(2, i-1) + vec_GrayCode[nBackIdx];
            nBackIdx--;
        }
    }
    return vec_GrayCode;

}
