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

void debug_print( const TreeNode* pNode)
{

}

TreeNode* create_tree(const std::vector<int>& vec_data)
{
  //need to create tree from level-order  traversal
  TreeNode* pNode = new TreeNode(vec_data[0]);
  int height = log2(vec_data.size()+1);
  int nDepth = 0;
  std::queue<TreeNode*> queueTree;
  queueTree.push(pNode);
  while (!queueTree.empty())
  {
    pNode = queueTree.front();
    queueTree.pop();
    if( pNode != nullptr && nDepth < height)
    {
      int nLeftIndex = 2*nDepth + 1;
      int nRightIndex = 2*nDepth + 2;
      TreeNode* pLeft = nullptr;
      TreeNode* pRight = nullptr;
      if(vec_data[nLeftIndex] != -99)
      {
        pLeft = new TreeNode(vec_data[nLeftIndex]);
      }

      if(vec_data[nRightIndex]!= -99)
      {
        pRight = new TreeNode(vec_data[nRightIndex]); 
      }

      queueTree.push(pLeft);
      queueTree.push(pRight);
      pNode->left = pLeft;
      pNode->right = pRight;
      nDepth++;
    }
  }
}
