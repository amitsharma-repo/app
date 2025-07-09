
#include<rotatate_array.h>
#include<iostream>
void rotate(std::vector<int>& nums, int k) {  
   if (nums.size() <= k)
      k = k % nums.size();
   int nBckSize = nums.size() - k;
   std::vector<int> vecBck;
   vecBck.reserve(nBckSize);
   for(int nIdx = 0; nIdx < nBckSize; ++nIdx)
   {
       vecBck.push_back(nums[nIdx]);
   }
   for(int nIdx = nBckSize; nIdx < nums.size(); ++nIdx)
   {
       nums[nIdx - nBckSize] = nums[nIdx];
   }
   int nStartIdx = nums.size() - nBckSize;
   for (int nIdx = 0; nIdx < vecBck.size(); ++nIdx)
   {
       nums[nStartIdx] = vecBck[nIdx];
       nStartIdx++;
   }
}

