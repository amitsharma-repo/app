#include <pthread.h>

std::vector<int> towsum(const std::vector<int>& nums, int target)
{
  std::vector<int> resultIndex;
  std::map<int, int> mapValue_idx;
  for (int index =0; index <nums.size(); ++index)
  {
    if (mapValue_idx.find(nums[index]) != mapValue_idx.end())
    {
      int idxmap = mapValue_idx[nums[index]];
      resultIndex.push_back(idxmap);
      resultIndex.push_back(index);
      break;
    }
    mapValue_idx[target- nums[index]] = index;
  }
  return resultIndex;
}
