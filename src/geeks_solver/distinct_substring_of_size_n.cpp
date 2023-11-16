#include "distinct_substring_of_size_n.h"
#include <set>
using namespace std;
bool checkIfExist(std::string& s, int nIndex, const std::set<char>& setDistinct);
int countGoodSubstrings(std::string s)
{
  if(s.size() < 3)
    return 0;
  int nSlidingIndex = 0;
  int nCountDistinct = 0;

  for (; nSlidingIndex < s.size() -2; ++nSlidingIndex) 
  {
    set<char> setDistinct;
    setDistinct.insert(s[nSlidingIndex]);
    if (!checkIfExist(s, nSlidingIndex +1, setDistinct))
      continue;
    setDistinct.insert(s[nSlidingIndex +1]);
    if (!checkIfExist(s, nSlidingIndex +2, setDistinct)) 
      continue;
    nCountDistinct++; 
  }
  return nCountDistinct;
}

bool checkIfExist(std::string& s, int nIndex, const std::set<char>& setDistinct)
{
  if(setDistinct.find(s[nIndex]) != setDistinct.end())
  {
    return false;
  }
  return true;
}
