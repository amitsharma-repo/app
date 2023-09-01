//Solution is O(n) time complexity
#include "partition_list.h"
#include "util_struct.h"

List* partition_smaller(List* head, int x)
{
  //debug_print(head);
  List* pTraverse = head;
  //Find Node with n_value_ue x
  pTraverse = head;
  List* pPrevTraverse = nullptr;
  List* pListSmaller = nullptr;
  while (pTraverse != nullptr)
  {
    if (pTraverse->n_value_ < x)
    {
      if (pListSmaller == nullptr)
      {
        //case if pTraverse Node is not starting node
        if (pPrevTraverse != nullptr)
        {
            List* pTemp = pTraverse;
            pPrevTraverse->p_next_ = pTraverse->p_next_;
            pTemp->p_next_ = head;
            head = pTemp;
        }
        pListSmaller = pTraverse;
        pPrevTraverse = pTraverse;
        pTraverse = pTraverse->p_next_;
      }
      else
      {
        if (pPrevTraverse->n_value_ >= x)
        {
          List* pTemp = pTraverse;
          pPrevTraverse->p_next_ = pTraverse->p_next_;
          pTraverse = pPrevTraverse->p_next_;
          pTemp->p_next_ = pListSmaller->p_next_;
          pListSmaller->p_next_ = pTemp;
          pListSmaller = pTemp;
        }
        else
        {
          pPrevTraverse = pTraverse;
          pTraverse = pTraverse->p_next_;
          pListSmaller = pPrevTraverse;
        }
      }
    }
    else
    {
        pPrevTraverse = pTraverse;
        pTraverse = pTraverse->p_next_;
    }
  }
  return head;
}

