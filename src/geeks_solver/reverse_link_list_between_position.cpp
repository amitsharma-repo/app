#include <reverse_link_list.h>
#include <util_struct.h>
List* reverseBetween_position(List* head, int left, int right)
{
  List* pPrevLeft = nullptr;
        List* pPrevRight = nullptr;
        List* pTraverseNode = head;
        int nCnt = 1;
        while (pTraverseNode->p_next_ != nullptr)
        {
            nCnt++;
            if (nCnt == left)
            {
                pPrevLeft = pTraverseNode;
            }

            if (nCnt == right)
            {
               pPrevRight = pTraverseNode->p_next_;
               break;
            }
            pTraverseNode = pTraverseNode->p_next_;
        }
        if (pPrevRight == nullptr)
        {
            return head;
        }
        List* pConnector = pPrevLeft;
        //case of pConnector = nullptr;
        if(left == 1)
        {
          pPrevLeft = head;
        }
        else
        {
          pPrevLeft = pPrevLeft->p_next_;
        }
        //reversing logic
        pTraverseNode = pPrevLeft;
        List* pNext = pTraverseNode->p_next_;
        while ( pTraverseNode != pPrevRight)
        {
            List* pTemp = pNext->p_next_;

            //reversing pointer
            pNext->p_next_ = pTraverseNode;

            //shifting pinters
            pTraverseNode = pNext;
            pNext = pTemp;
        }

        pPrevLeft->p_next_ = pNext;
        if (pConnector == nullptr)
        {
          return pPrevRight;
        }
        pConnector->p_next_ = pPrevRight;
        return head;
}
