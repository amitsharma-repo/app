#include "unique_binary_tree.h"

std::vector<std::vector<TreeNode*>> vecListBST;
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


void generateBST(int nNode)
{
    for (auto it: vecListBST[nNode -2])
    {

        //BST Permuation_1 : creating clone of BST of length n-2
        TreeNode* pChildNode = make_clone(it);
       
        //Inserting new Node as root Node.
        TreeNode* pNode = new TreeNode(nNode);
        pNode->left = pChildNode;
        std::cout << "Inserting new Node as root node " << pNode->val << std::endl;
        vecListBST[nNode-1].push_back(pNode);

        //BST Permuation_2 : creating clone of BST of length n-2
        TreeNode* pSubNode = make_clone(it);
        if (pSubNode->right != nullptr)
        {
            TreeNode* pTemp = pSubNode;
            while(pTemp->right->right != nullptr)
            {
                pTemp = pTemp->right;;
            }

            //inserting as leaf Node
            pNode = new TreeNode(nNode);
            pTemp->right->right = pNode;
            vecListBST[nNode-1].push_back(pSubNode);

            //BST Permuation_1 : creating clone of BST of length n-2
            pSubNode = make_clone(it);
            pTemp = pSubNode;

            //inserting as parent node of largest Node.
            pNode = new TreeNode(nNode);
            pNode->left = pNode->right;
            pTemp->right = pNode;
            vecListBST[nNode-1].push_back(pSubNode);

        }
        else //root node does not have any right node
        {
            pNode = new TreeNode(nNode);
            pSubNode->right = pNode;
            std::cout << "root node does not having any right node " << pSubNode->val << std::endl;
            vecListBST[nNode-1].push_back(pSubNode);
        }
    }
}
vector<TreeNode*> generateTrees(int n) {
    vecListBST.resize(n);
    //Default for first single Node BST
    TreeNode *pNode = new TreeNode(1);
    vecListBST[0].push_back(pNode);
    for (int nNode = 2; nNode <= n; nNode++)
    {
        std::cout << "node value is " << nNode << std::endl;
        generateBST(nNode);
    }
    return vecListBST[n-1];
}
