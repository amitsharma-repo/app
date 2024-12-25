#include "median_of_two_sorted_array.h"
double findMedianSortedArrays(std::vector<int>& nums_x, std::vector<int>& nums_y)
{
  int nStart_x, nStart_y = 0;
  int nEnd_x = nums_x.size() - 1;
  int nEnd_y = nums_y.size() - 1;
  int nMedianIdx = (nEnd_x + nEnd_y + 1)/ 2;
  int x1, x2, y1, y2;
  int nMedian = 0;
  bool bFound = false;
  while (!bFound)
  {
    int nMid_x = (nEnd_x - nStart_x) / 2;
    x1 = nums_x[nMid_x];
    x2 = nums_x[nMid_x + 1];
    int nMid_y = nMedianIdx- nMid_x - 1; 
    y1 = nums_x[nMid_y];
    y2 = nums_x[nMid_y + 1];
  
    if (x1 <= y2 && y1 <= x2)
    {
      if ((nEnd_x + nEnd_y) % 2 != 0) 
      {
        if (y1 > y2)
          nMedian = y2;
        else
          nMedian = y1;
      }
      else
      {
        nMedian = (y2 + y1)/2;
      }
      bFound = true;
    }
    else if (x1 > y2)
    {
      nEnd_x = nMid_x;  
    }
    else //y1 > x2
    {
      nStart_x = nMid_x + 1;
    } 
  }
  return nMedian;
}
