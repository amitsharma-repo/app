#include<jump_game.h>
#include <vector>
int jump(std::vector<int>& nums) 
{
  std::vector<int> arrMove;
  if (nums.size() == 1)
  {
    return 0;
  }

  for (auto it: nums)
  {
    arrMove.push_back(0);
  }
  arrMove[0] = 0;

  for (int i = 0 ; i < arrMove.size(); ++i)
  {
    if (i != 0 && (arrMove[i] == 0 || arrMove[i] >arrMove[i-1] +1))
    {
      arrMove[i] = arrMove[i-1] +1;
    }

    int jump = nums[i];
    for ( int k = 1; k <= jump; ++k)
    {
       if ( i+ k > nums.size() -1)
       {
          continue;
       }

       if (arrMove[i + k] == 0 || arrMove[i + k] > arrMove[i] + 1)
       {
         arrMove[i + k] = arrMove[i] +1;
       }
    }
  }

  return arrMove[nums.size() -1];
}
