#include <zig_zag_conversion.h>
#include<iostream>
std::string zig_zag_convert(std::string s, int numRows)
{
    if(numRows == 1)
        return s;
    std::string strResult;
    for( int nIdx = 0; nIdx < numRows && nIdx < s.size(); ++nIdx) 
    {
        int nNxtIdx = nIdx;
        int nPrevIdx = nNxtIdx;
        bool b_down = true;
        strResult.push_back(s[nNxtIdx]);
        //std::cout << "nIndex is " << nNxtIdx << "size is " << s.size() << std::endl;
        while(nNxtIdx < s.size() ) {
            if(nPrevIdx != nNxtIdx ) {
                //std::cout << "row is " << nIdx << "nxt index is " << nNxtIdx << std::endl;
                strResult.push_back(s[nNxtIdx]);
            }
            nPrevIdx = nNxtIdx;
            if( b_down ) {
                nNxtIdx = nNxtIdx + ((numRows - nIdx - 1) * 2);
                b_down =false;
            }
            else {
                nNxtIdx = nNxtIdx + (nIdx * 2);
                b_down = true;
            }
        }
    }
   return strResult;
}
