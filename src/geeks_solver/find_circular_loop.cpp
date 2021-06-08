#include<iostream>
#include<find_circular_loop.h>
bool check_circular_loop(std::vector<int>& arrCircular)
{
    std::vector<bool> arrVisited;
    for(int i =0; i< arrCircular.size(); ++i)
      arrVisited.push_back(false);  
    for(int i=0; i< arrCircular.size(); ++i ) {
        if(arrVisited[i] == false) {
            int nLoopLen = 0;
            bool bSign = arrCircular[i] > 0 ? true: false;
            if( dfs_check_loop(i, arrVisited, arrCircular, nLoopLen, bSign) ) {
                return true;
            }
            else {
               for(int i =0; i< arrCircular.size(); ++i)                                   
                    arrVisited[i] = false;  
            }
        }
    }
    return false;
}
bool dfs_check_loop(int nIndex, std::vector<bool>& arrVisited, const std::vector<int>& arrCircular, int& nLoopLen, bool bSign)
{
    if(arrVisited[nIndex] == true)
    {
        if( nLoopLen > 1)
           return true; 
        else 
           return false;
    }
    nLoopLen++;
    int nMove = arrCircular[nIndex];    
    arrVisited[nIndex]= true;
    int newIndex = nIndex + nMove;
    if( newIndex< 0) {
        newIndex= arrCircular.size() + newIndex;
    }
    if(newIndex > (arrCircular.size() - 1)) {
        newIndex %= arrCircular.size();
    }
    if((arrCircular[newIndex] > 0) == (bSign) && newIndex != nIndex) {
         return dfs_check_loop(newIndex, arrVisited, arrCircular, nLoopLen, bSign);
    }
    else {
        return false;
    }
    return false;
}

