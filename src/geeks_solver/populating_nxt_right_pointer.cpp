#include<populating_nxt_right_pointer.h>
#include<queue>
struct info{
  Node* pNode;
  int nLevel;
};
Node* connect(Node* root) {
    if(root == nullptr)
        return root;
    std::queue<info> bfs_queue;
    bfs_queue.push({root, 0});
    int nPrev_level = 0;
    Node* pPrev_Node = root;    
    while(bfs_queue.size() > 0) {
        Node* pCurr_Node = bfs_queue.front().pNode;
        int nCurr_level = bfs_queue.front().nLevel;
        bfs_queue.pop();
        
        if(pCurr_Node == root || nCurr_level != nPrev_level) {
            pPrev_Node->next = nullptr;
        }
        else {
            pPrev_Node->next = pCurr_Node;
        }
        nPrev_level = nCurr_level;
        pPrev_Node = pCurr_Node;
        if(pCurr_Node->left != nullptr)
        {
            bfs_queue.push({pCurr_Node->left, nCurr_level +1});
            bfs_queue.push({pCurr_Node->right, nCurr_level +1});
        }
        
    }
    return root;
}
