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

NodeNxt* connectNxt(NodeNxt* root) {

  if (root == nullptr)
    return root;
  std::queue<NodeNxt*> pLevelOrderQueue;
  pLevelOrderQueue.push(root);
  pLevelOrderQueue.push(nullptr);
  NodeNxt* pNodeNxt = nullptr;
  while (!pLevelOrderQueue.empty())
  {
      NodeNxt* pPrevNodeNxt = pNodeNxt;
      pNodeNxt = pLevelOrderQueue.front();
      if (pPrevNodeNxt != nullptr)
      {
          pPrevNodeNxt->next = pNodeNxt;
      }
      pLevelOrderQueue.pop();
      if (pNodeNxt != nullptr)
      {
          if(pNodeNxt->left != nullptr)
          {
              pLevelOrderQueue.push(pNodeNxt->left);
          }
          if (pNodeNxt->right != nullptr)
          {
              pLevelOrderQueue.push(pNodeNxt->right);
          }
      }
      else
      {
        if(pLevelOrderQueue.size() != 0)
        {
          pLevelOrderQueue.push(nullptr);
        }
      }
  }
  return root;
}
