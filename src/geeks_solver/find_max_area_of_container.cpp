#include<find_max_area_of_container.h>
#include<algorithm>
int find_max_area(const std::vector<int>& heights)
{
    int nStartIdx= 0;
    int nEndIdx= heights.size() -1;
    int nMaxArea =0;
    while( nStartIdx < heights.size() -1 && nEndIdx > 0 &&  nStartIdx < nEndIdx )
    {
        int nArea = std::min( heights[nStartIdx], heights[nEndIdx]) *( nEndIdx - nStartIdx);
        if( nMaxArea < nArea )
           nMaxArea = nArea;
        if( heights[nStartIdx] < heights[nEndIdx] )
            nStartIdx++;
        else
            nEndIdx--;
    }
    return nMaxArea;
};

