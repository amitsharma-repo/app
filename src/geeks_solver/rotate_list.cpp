#include<iostream>
#include <util_struct.h>
#include <rotate_list.h>

bool updateNode( List* head, List*& pNode, int& nNxtCnt)
{
  if(nNxtCnt == 0)
  {
    return false;
  }
  pNode = head;
  nNxtCnt--;
  return true;
}
List* rotateList(List* pHead, int k)
{
  List* pTraverseNode = pHead;
  List* pPrevTraverse = nullptr;
  int nNxtCnt = k-1;
  if (pHead == nullptr || pHead->p_next_ == nullptr || nNxtCnt < 0)
  {
    return pHead;
  }
  while ( pTraverseNode->p_next_ != nullptr || updateNode(pHead, pTraverseNode, nNxtCnt))
  {
    if (nNxtCnt > 0)
    {
      nNxtCnt--;
    }
    else
    {
      pPrevTraverse = (pPrevTraverse == nullptr) ? pHead : pPrevTraverse->p_next_;
    }

    pTraverseNode = pTraverseNode->p_next_;
  }
  pTraverseNode->p_next_ = pHead;
  pHead = pPrevTraverse->p_next_;
  pPrevTraverse->p_next_ = nullptr;
 return pHead;
}
