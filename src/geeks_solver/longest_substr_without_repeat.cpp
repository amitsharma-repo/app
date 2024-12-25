#include "longest_substr_without_repeat.h"
#include <map>


int lengthOfLongestSubstring(std::string s)
{
  std::map<char, int> setChar;
  int nLongestLen = 0;
  int nSubStrlen = 0;
  int nIdx = 0;
  int nStartIdx = 0;
  for (auto ch: s)
  {
    auto it = setChar.find(ch);
    if (it != setChar.end())
    {
      int nIndex = it->second;
      if (nStartIdx <= nIndex)
      {
        nSubStrlen = nIdx - nIndex;
        nStartIdx = nIndex;
      }
      else
      {
        nSubStrlen++;
      }
      setChar[ch] =  nIdx;
    }
    else
    {
      nSubStrlen++;
      setChar.insert(std::make_pair(ch, nIdx));
    }
    if (nSubStrlen > nLongestLen)
    {
      nLongestLen  = nSubStrlen;
    }
    nIdx++;
  }
  return nLongestLen;
}
