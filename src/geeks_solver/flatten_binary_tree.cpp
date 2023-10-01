#include<flatten_binary_tree.h>
#include<util_struct.h>

    TreeNode* attachNode(TreeNode* pHead, TreeNode* pLeft, TreeNode* pRight)
    {
        TreeNode* pTraverse = pHead;
        if (pLeft != nullptr)
        {
            pTraverse->right = pLeft;
            while (pTraverse->right != nullptr)
            {
                pTraverse = pTraverse->right;
            }
        }
        if (pRight != nullptr)
        {
            pTraverse->right = pRight;
        }
        return pHead;
    }
    TreeNode* recurseInorder(TreeNode* pTreeNode)
    {
        if (pTreeNode == nullptr)
            return nullptr;
        TreeNode* pNode = new TreeNode();
        pNode->val = pTreeNode->val;
        TreeNode* pLeftNode = recurseInorder(pTreeNode->left);
        TreeNode* pRightNode = recurseInorder(pTreeNode->right);
        attachNode(pNode, pLeftNode, pRightNode);

        return pNode;
    }
    void flatten(TreeNode* root) {
      if (root == nullptr)
            return ;
        TreeNode *pNode = recurseInorder(root);
        while(pNode->right != nullptr)
        {
            root->left = nullptr;
            root->right = pNode->right;
            root = root->right;
            pNode = pNode->right;
        }
        root->right = nullptr;
    }

