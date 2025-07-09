#include <remove_dublicate.h>
#include <iostream>
#include <vector>
using namespace std;
void shift_by_idx(std::vector<int>& nums, int nShift, int nShiftStartIdx, int nEnd)
{
  for (int i = nShiftStartIdx; i <= nEnd; i++)
  {
    nums[i-nShift] = nums[i];
  }
  
} 
int removeDublicaateIterate(int nStart, int nShift, vector<int>& nums, int& nShiftStartIdx)
{
  if (nStart >= nums.size())
  {
    return nShift;
  }

  int nShiftNxt = 0;
  nShiftStartIdx = nStart;
  while( nStart < nums.size())
  {
    int nCnt = 1;
    while(nStart+1 < nums.size() && nums[nStart] == nums[nStart + 1])
    {
      ++nCnt;
      nStart = nStart + 1;
    }
    ++nStart;
    if (nCnt > 2)
    {
      nShiftNxt = nCnt + nShift- 2;
      break;
    }
    else
    {
      nShiftNxt = nShift;
    }
  }
  shift_by_idx(nums, nShift, nShiftStartIdx, nStart -1); 
  return removeDublicaateIterate(nStart, nShiftNxt, nums, nShiftStartIdx);
}

int removeDuplicates(vector<int>& nums) {
  int nStartIdx;
  int nRet = removeDublicaateIterate(0, 0, nums, nStartIdx);
  return nums.size() - nRet;
}
