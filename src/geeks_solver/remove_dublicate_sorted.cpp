#include<remove_dublicate_sorted.h>
#include<vector>
#include<iostream>
int removeDuplicatesSorted(std::vector<int>& nums)
{
   int nCnt = 0;
   int nSkipCnt = 0;
   int nNxtIdx = 0;
   while(nCnt < nums.size() - 1)
   {
      int nStartIdx = nCnt;
      while(nCnt < nums.size()  - 1 && nums[nCnt] == nums[++nCnt] && ++nSkipCnt);
      nNxtIdx++;
      nums[nNxtIdx] = nums[nCnt];
   }
   return nums.size() - nSkipCnt ;
}
