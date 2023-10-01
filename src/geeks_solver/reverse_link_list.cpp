#include <reverse_link_list.h>
#include <util_struct.h>
List* reverseBetween(List* head, int left, int right)
{
  List* pPrevLeft = nullptr;
        List* pPrevRight = nullptr;
        List* pTraverseNode = head;
        while (pTraverseNode->p_next_ != nullptr && (pPrevLeft == nullptr || pPrevRight == nullptr))
        {
            if (pPrevLeft == nullptr && pTraverseNode->p_next_->n_value_ == left)
            {
                pPrevLeft = pTraverseNode;
            }
            else if (pPrevRight == nullptr && pTraverseNode->p_next_->n_value_ == right)
            {
               pPrevRight = pTraverseNode->p_next_;
            }
            pTraverseNode = pTraverseNode->p_next_;
        }
        if (pPrevLeft == nullptr || pPrevRight == nullptr)
        {
            return head;
        }
        List* pConnector = pPrevLeft;
        pPrevLeft = pPrevLeft->p_next_;

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
        pConnector->p_next_ = pPrevRight;
        pPrevLeft->p_next_ = pNext;
        return head;
}
