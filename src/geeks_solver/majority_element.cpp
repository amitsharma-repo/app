#include <majority_element.h>
#include <iostream>

int majorityElement(std::vector<int>& nums)
{
  int nCount = 0;
  int nElement = 0;
  for (int nIdx = 0; nIdx < nums.size(); ++nIdx)
  {
    if (nCount == 0)
    {
      nElement = nums[nIdx];
      nCount = 1;
      continue;
    }

    if (nums[nIdx] == nElement)
    {
      nCount++;
    }
    else
    {
      nCount--;
    }
  }
  return nElement;
}
