#include<queue>
using namespace std;
#include<reverse_nodes_in_k_group.h>
bool swap(List *& pNode, List *& pNxt_node) 
{
    if(pNxt_node == nullptr)
        return false;
    List* pTempNode = pNxt_node->p_next_;
    pNxt_node->p_next_ = pNode;
    pNode = pNxt_node;
    pNxt_node = pTempNode;
    return true;
}
List* reverseGroup(List*& pNode, int k, bool& status)
{
    int nLen = k - 1;
    List* pNxtNode = pNode->p_next_;
    pNode->p_next_ = nullptr;
    while( nLen-- > 0) {
        if(!swap(pNode, pNxtNode)) {
            reverseGroup(pNode, k - (nLen + 1), status);
            status = false;
            return nullptr;
        }
    }

     status = true;
     return pNxtNode;
}
List* reverseKGroup(List* head, int k) {
    if( head->p_next_ == nullptr)
        return head;
    bool bKGroup = true;
    List* pNode = head;
    std::queue<List*> queue_StartNode;
    std::queue<List*> queue_EndNode;
    queue_StartNode.push(pNode);
    head = nullptr;
    while( 1 )
    {
        bool bStatus = false;
        List* pNxtStrtNode = reverseGroup( pNode, k, bStatus);
        if( !bStatus) {
            if(head == nullptr )                                                    
               head = pNode;
            break;
        }
        if(head == nullptr )
            head = pNode;
        else
           queue_EndNode.push(pNode);
        if( pNxtStrtNode != nullptr) {
            queue_StartNode.push(pNxtStrtNode);
            pNode = pNxtStrtNode;
        }
        else {
            break;
        }

    }
    while(!queue_EndNode.empty())
    {
        List* start = queue_StartNode.front();
        queue_StartNode.pop();
        if( queue_EndNode.empty()) {
            start->p_next_ = nullptr;
        }
        else{
            start->p_next_ = queue_EndNode.front();
            queue_EndNode.pop();
        }
    }
     while(!queue_StartNode.empty()) {
         List* start = queue_StartNode.front();
         queue_StartNode.pop();
         if( queue_StartNode.empty() ) {
             start->p_next_ = nullptr;
         }
         else {
             start->p_next_ = queue_StartNode.front();
             queue_StartNode.pop();
         }
     }
    return head;
}
