#include<util_struct.h>
#include <queue>
void debug_print( const List* p_node )
{
    std::cout << "node value " << std::endl;
    while( p_node != nullptr )
    {
        std::cout << p_node->n_value_ << " ";
        p_node = p_node->p_next_;
    }
}   

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

List* create_link_list(const std::vector<int>& vec_data)                        
{                                                                               
    List *pList , *pStart;                                                      
    pList = pStart = nullptr;                                                   
                                                                                
    for_each( vec_data.begin(), vec_data.end(), [ & ](int nData){               
            if( pList == nullptr) {                                             
                pList = new List( nData );                                      
                pStart = pList;                                                 
            }                                                                   
            else {                                                              
                pList->p_next_ = new List( nData );                             
                pList = pList->p_next_;                                         
            }                                                                   
            });                                                                 
                                                                                
    return pStart;                                                              
}   

TreeNode* make_clone(TreeNode* pNode)
{         
    if(pNode == nullptr)
        return nullptr;
    TreeNode* pNewNode = new TreeNode(pNode->val);
    if (pNode->left != nullptr)
    {
        pNewNode->left = make_clone(pNode->left);
    }
    if (pNode->right != nullptr)
    {
        pNewNode->right = make_clone(pNode->right);
    }
    return pNewNode;
}

void debug_print( const TreeNode* pNode)
{

}

TreeNode* create_tree(const std::vector<int>& vec_data)
{
    if (vec_data.empty() || vec_data[0] == -99)
    {
        return nullptr;
    }

    std::queue<TreeNode*> queueTree;
    TreeNode* pRoot = new TreeNode(vec_data[0]);
    queueTree.push(pRoot);
    std::size_t index = 1;

    while (!queueTree.empty() && index < vec_data.size())
    {
        TreeNode* pNode = queueTree.front();
        queueTree.pop();

        if (index < vec_data.size() && vec_data[index] != -99)
        {
            pNode->left = new TreeNode(vec_data[index]);
            queueTree.push(pNode->left);
        }
        ++index;

        if (index < vec_data.size() && vec_data[index] != -99)
        {
            pNode->right = new TreeNode(vec_data[index]);
            queueTree.push(pNode->right);
        }
        ++index;
    }

    return pRoot;
}
