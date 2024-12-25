#include "merge_sort_array.h"
#include <iostream>
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  if (n == 0)
  {
      return;
  }
  if (m == 0)
  {
      nums1 = nums2;
  }
  int nLeftIdx = m - 1;
  int  nRightIdx = n -1;
  int nFinalIdx = m + n -1;
  while (nLeftIdx >= 0 && nRightIdx >= 0)
  {
      if (nums1[nLeftIdx] <= nums2[nRightIdx])
      {
          nums1[nFinalIdx] = nums2[nRightIdx];
          nRightIdx--;
      }
      else
      {
          nums1[nFinalIdx] = nums1[nLeftIdx];
          nLeftIdx--;
      }
      nFinalIdx--;
  }
  while (nRightIdx >= 0)
  {
       nums1[nFinalIdx] = nums2[nRightIdx];
          nRightIdx--;
           nFinalIdx--;
  }

}
