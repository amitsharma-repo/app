//Solution is O(n) time complexity
#include "partition_list.h"
#include "util_struct.h"

List* partition(List* head, int x)
{
  //debug_print(head); 
  List* pTraverse = head;
  //Find Node with value x
  List* pNode = nullptr;
  bool bFirstHalf = true;
  while (pTraverse != nullptr)
  {
    if (pTraverse->n_value_ == x)
      break;
    pTraverse = pTraverse->p_next_;
  }
  pNode = pTraverse;
  pTraverse = head;
  List* pListSmaller = nullptr;
  List* pListGratter = pNode;
  while (pTraverse != nullptr)
  {
    if (pTraverse->n_value_ <= x)
    {
      if (bFirstHalf)
      {
        if (pListSmaller == nullptr)
        {
          pListSmaller = pTraverse;
          pTraverse = pTraverse->p_next_;
          continue;
        }
        pListSmaller->p_next_ = pTraverse;
        if(pTraverse->n_value_ == pNode->n_value_)
        {
          if ( pTraverse != pNode)
          {
            List* pTemp = pNode->p_next_;
            pNode->p_next_ = pTraverse;
            pTraverse = pTraverse->p_next_;
            pNode = pNode->p_next_;
            pNode->p_next_ = pTemp;
          }
          else
          {
            bFirstHalf = false;
            pTraverse = pListGratter->p_next_; 
          }
        }
        else
        {
          pListSmaller = pTraverse;
          pTraverse = pTraverse->p_next_;
        }
      }
      else
      {
        pListSmaller->p_next_ = pTraverse;
        pTraverse = pTraverse->p_next_;
        pListSmaller = pListSmaller->p_next_;
        pListSmaller->p_next_ = pNode;
      }
    }
    else if ( pTraverse->n_value_ > x)
    {
      if (!bFirstHalf)
      {
        pListGratter->p_next_ = pTraverse;
        pListGratter = pTraverse;
        pTraverse = pTraverse->p_next_;
      }
      else
      {
        //insert Node in front of pListGratter
        List* pTemp = pListGratter->p_next_;
        pListGratter->p_next_ = pTraverse;
        pTraverse = pTraverse->p_next_;
        pListGratter = pListGratter->p_next_;
        pListGratter->p_next_ = pTemp;
      }
    }
    //we arrive pTraverse == node
    //after this condition change. pTraverse move to other half and 
    //all smaller node need to be inserted after pListSmaller and perform jump of pListGratter if we encounter any smaller node
  }
  pListGratter->p_next_ = nullptr;
  return head;
}

