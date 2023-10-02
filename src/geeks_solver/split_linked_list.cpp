#include "split_linked_list.h"
#include "util_struct.h"
vector<List*> splitListToParts(List* head, int k)
{
  int nListLen = 0;
  List* pTraverse = head;
  while (pTraverse != nullptr)
  {
    nListLen++;
    pTraverse = pTraverse->p_next_;
  }
  int nSplitListLen = nListLen / k;
  int nSplitListLen_plus_1 = nListLen % k;
  vector<List*> retSplitList;
  pTraverse = head;
  int nNullListCnt = 0;
  if (nListLen < k)
  {
    nNullListCnt = k - nListLen;
  }
  while (pTraverse != nullptr)
  {
    int nLen = nSplitListLen;
    retSplitList.push_back(pTraverse);

    while (pTraverse != nullptr && --nLen > 0)
      pTraverse = pTraverse->p_next_;

    if (nLen == 0 && pTraverse != nullptr &&  nSplitListLen_plus_1-- > 0)
      pTraverse = pTraverse->p_next_;
    if (pTraverse != nullptr)
    {
        List* pTemp = pTraverse->p_next_;
        pTraverse->p_next_ = nullptr;
        pTraverse = pTemp;
    }
  }
  while (nNullListCnt-- > 0)
    {
      retSplitList.push_back(nullptr);
    }
  return retSplitList;
}

