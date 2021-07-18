#include<swaping_nodes_in_linklist.h>
List* swap_adjacent(List* pNode, List* pNxt_Node)
{
    if(pNxt_Node == nullptr)
        return pNode;
    List* pTmpNode = pNxt_Node->p_next_;
    List* pPrevNode = pNode;
    pNxt_Node->p_next_ = pNode;
    pNode = pTmpNode;
    if( pNode != nullptr) {
        pPrevNode->p_next_ = swap_adjacent(pNode, pNode->p_next_);
    }
    else{
        pPrevNode->p_next_ = nullptr;
    }
    return pNxt_Node;
}
List* swapPairs(List* head) {
    List* pNode = head;
    if(pNode != nullptr)
         return swap_adjacent(pNode, pNode->p_next_);
    else
        return pNode;
}
