
#include <util_struct.h>
#include <sortedListToBST.h>
/**
 * Definition for singly-linked list.
 * struct List {
 *     int n_value_;
 *     List *p_next_;
 *     List() : n_value_(0), p_next_(nullptr) {}
 *     List(int x) : n_value_(x), p_next_(nullptr) {}
 *     List(int x, List *p_next_) : n_value_(x), p_next_(p_next_) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int n_value_;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : n_value_(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : n_value_(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : n_value_(x), left(left), right(right) {}
 * };
 */
    List* find_mid(List* pFirst, List* pEnd)
    {
        int nFirstValue = pFirst == nullptr ? -1 : pFirst->n_value_;
        int nEndValue = pEnd == nullptr ? -1 : pEnd->n_value_;

        List* pMidPtr = pFirst;
        List* pNext = pFirst;

        while (pNext != nullptr && pNext->p_next_ != pEnd && pNext != pEnd)
        {
            pNext = pNext->p_next_->p_next_;
            pMidPtr = pMidPtr->p_next_;
        }
        return pMidPtr;
    }

    TreeNode* recurseList(List* pStart, List* pEnd)
    {
        if(pStart == pEnd || pStart == nullptr)
        {
            return nullptr;
        }
        if (pStart->p_next_ == pEnd)
        {
            return new TreeNode(pStart->n_value_);
        }
        List* pMid = find_mid(pStart, pEnd);
        TreeNode* pLeftTreeNode = nullptr;
        TreeNode* pRightTreeNode = nullptr;

        pLeftTreeNode = recurseList(pStart, pMid);
        pRightTreeNode= recurseList(pMid->p_next_, pEnd);


        TreeNode* pTreeMidNode = new TreeNode(pMid->n_value_);

        pTreeMidNode->left = pLeftTreeNode;
        pTreeMidNode->right = pRightTreeNode;

        return pTreeMidNode;
    }
    TreeNode* sortedListToBST(List* head)
    {
       TreeNode *pRetTreeNode = recurseList(head, nullptr);
       return pRetTreeNode;
    }
