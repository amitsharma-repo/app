#include<next_rightptr_tree.h>
#include<iostream>
#include<queue>

void debug_print(NodeNxt* pNode)
{
}
void create_tree_ptr(const std::vector<int>& vec_data, NodeNxt*& pRoot)
{
  //need to create tree from level-order  traversal
  NodeNxt* pNodeNxt = new NodeNxt(vec_data[0]);
  pRoot = pNodeNxt;
  int height = log2(vec_data.size()+1);
  int nDepth = 0;
  std::queue<NodeNxt*> queueTree;
  queueTree.push(pNodeNxt);
  while (!queueTree.empty())
  {
    pNodeNxt = queueTree.front();
    queueTree.pop();
    if( pNodeNxt != nullptr && nDepth < height)
    {
      int nLeftIndex = 2*nDepth + 1;
      int nRightIndex = 2*nDepth + 2;
      NodeNxt* pLeft = nullptr;
      NodeNxt* pRight = nullptr;
      if(vec_data[nLeftIndex] != -99)
      {
        pLeft = new NodeNxt(vec_data[nLeftIndex]);
      }

      if(vec_data[nRightIndex]!= -99)
      {
        pRight = new NodeNxt(vec_data[nRightIndex]);
      }

      queueTree.push(pLeft);
      queueTree.push(pRight);
      pNodeNxt->left = pLeft;
      pNodeNxt->right = pRight;
      nDepth++;
    }
  }
}
