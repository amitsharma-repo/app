#include <remove_element.h>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0)
    {
      return 0;
    }
    int nLastIdx = nums.size() - 1;
    int nStartIdx = 0;
    while( nStartIdx < nLastIdx)
    {
      while(nums[nLastIdx] == val && nStartIdx < nLastIdx)
      {
          nLastIdx--;
      }
      while(nStartIdx < nLastIdx && nums[nStartIdx] != val)
      {
          nStartIdx++;
      }
      if (nStartIdx >= nLastIdx)
      {
          break;
      }

      nums[nStartIdx] = nums[nLastIdx];
      nStartIdx++;
      nLastIdx--;
    }
    if (nums[nLastIdx] == val)
    {
        nLastIdx--;
    }
    return  nLastIdx + 1;
}
