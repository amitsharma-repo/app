#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#include <math.h>
#include <set>
#include <algorithm>
#include <cstdio>
#include <tuple>
#include <iterator>
#include <functional>
#include <unordered_map>
#include <cmath>
#include <sstream>
#include <string>
#include <limits>
#include <cstdint>
#include <pthread.h>
#include <unordered_set>
#include <queue>
#include <stack>

#include <LRU_Cache.h>
#include <DSAProblems.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;
struct MinJumpinfo
{
    int curr;
    bool back_move;
    int count;
};

bool GeekSolver::check_word_break(const std::vector<std::string> &vec_input_string, const string &to_match)
{
    bool b_result_found = false;
    int n_match_idx = 0;
    for (auto iter = vec_input_string.begin(); iter != vec_input_string.end(); ++iter)
    {
        {
            std::string temp_string = *iter;
            bool match = true;
            for (int i = 0; i < temp_string.size() && n_match_idx < to_match.size(); iter++)
            {
                if (temp_string[i] != to_match[n_match_idx++])
                {
                    match = false;
                    break;
                }
            }
            if (!match)
            {
                n_match_idx = 0;
            }
            if (n_match_idx == to_match.size())
            {
                b_result_found = true;
                break;
            }
        }
    }
    return b_result_found;
}

std::vector<std::vector<TreeNode *>> vecListBST;

void generateBST(int nNode)
{
    for (auto it : vecListBST[nNode - 2])
    {

        // BST Permuation_1 : creating clone of BST of length n-2
        TreeNode *pChildNode = make_clone(it);

        // Inserting new Node as root Node.
        TreeNode *pNode = new TreeNode(nNode);
        pNode->left = pChildNode;
        std::cout << "Inserting new Node as root node " << pNode->val << std::endl;
        vecListBST[nNode - 1].push_back(pNode);

        // BST Permuation_2 : creating clone of BST of length n-2
        TreeNode *pSubNode = make_clone(it);
        if (pSubNode->right != nullptr)
        {
            TreeNode *pTemp = pSubNode;
            while (pTemp->right->right != nullptr)
            {
                pTemp = pTemp->right;
                ;
            }

            // inserting as leaf Node
            pNode = new TreeNode(nNode);
            pTemp->right->right = pNode;
            vecListBST[nNode - 1].push_back(pSubNode);

            // BST Permuation_1 : creating clone of BST of length n-2
            pSubNode = make_clone(it);
            pTemp = pSubNode;

            // inserting as parent node of largest Node.
            pNode = new TreeNode(nNode);
            pNode->left = pNode->right;
            pTemp->right = pNode;
            vecListBST[nNode - 1].push_back(pSubNode);
        }
        else // root node does not have any right node
        {
            pNode = new TreeNode(nNode);
            pSubNode->right = pNode;
            std::cout << "root node does not having any right node " << pSubNode->val << std::endl;
            vecListBST[nNode - 1].push_back(pSubNode);
        }
    }
}
vector<TreeNode *> generateTrees(int n)
{
    vecListBST.resize(n);
    // Default for first single Node BST
    TreeNode *pNode = new TreeNode(1);
    vecListBST[0].push_back(pNode);
    for (int nNode = 2; nNode <= n; nNode++)
    {
        std::cout << "node value is " << nNode << std::endl;
        generateBST(nNode);
    }
    return vecListBST[n - 1];
}

std::vector<int> towsum(const std::vector<int> &nums, int target)
{
    std::vector<int> resultIndex;
    std::map<int, int> mapValue_idx;
    for (int index = 0; index < nums.size(); ++index)
    {
        if (mapValue_idx.find(nums[index]) != mapValue_idx.end())
        {
            int idxmap = mapValue_idx[nums[index]];
            resultIndex.push_back(idxmap);
            resultIndex.push_back(index);
            break;
        }
        mapValue_idx[target - nums[index]] = index;
    }
    return resultIndex;
}
List *swap_adjacent(List *pNode, List *pNxt_Node)
{
    if (pNxt_Node == nullptr)
        return pNode;
    List *pTmpNode = pNxt_Node->p_next_;
    List *pPrevNode = pNode;
    pNxt_Node->p_next_ = pNode;
    pNode = pTmpNode;
    if (pNode != nullptr)
    {
        pPrevNode->p_next_ = swap_adjacent(pNode, pNode->p_next_);
    }
    else
    {
        pPrevNode->p_next_ = nullptr;
    }
    return pNxt_Node;
}

List *find_mid(List *pFirst, List *pEnd)
{
    int nFirstValue = pFirst == nullptr ? -1 : pFirst->n_value_;
    int nEndValue = pEnd == nullptr ? -1 : pEnd->n_value_;

    List *pMidPtr = pFirst;
    List *pNext = pFirst;

    while (pNext != nullptr && pNext->p_next_ != pEnd && pNext != pEnd)
    {
        pNext = pNext->p_next_->p_next_;
        pMidPtr = pMidPtr->p_next_;
    }
    return pMidPtr;
}

TreeNode *recurseList(List *pStart, List *pEnd)
{
    if (pStart == pEnd || pStart == nullptr)
    {
        return nullptr;
    }
    if (pStart->p_next_ == pEnd)
    {
        return new TreeNode(pStart->n_value_);
    }
    List *pMid = find_mid(pStart, pEnd);
    TreeNode *pLeftTreeNode = nullptr;
    TreeNode *pRightTreeNode = nullptr;

    pLeftTreeNode = recurseList(pStart, pMid);
    pRightTreeNode = recurseList(pMid->p_next_, pEnd);

    TreeNode *pTreeMidNode = new TreeNode(pMid->n_value_);

    pTreeMidNode->left = pLeftTreeNode;
    pTreeMidNode->right = pRightTreeNode;

    return pTreeMidNode;
}

/*Private*/
int binary_rotate_search(std::vector<int> &vec_nums, int n_start, int n_end, int target)
{
    int n_return_idx;
    if (n_end == n_start || n_start > n_end)
        return -1;
    int n_middle_idx = n_start + (n_end - n_start) / 2;
    if (vec_nums[n_middle_idx] == target)
        return n_middle_idx;
    bool b_first_half = true;
    if (vec_nums[n_middle_idx] < vec_nums[n_start])
    {                                                                          // pivot is at first half
        if (target <= vec_nums[n_end] && target >= vec_nums[n_middle_idx + 1]) // check in second half;
            b_first_half = false;
        else
            b_first_half = true;
    }
    else
    {                                                                        // pivot is at second half
        if (target <= vec_nums[n_middle_idx] && target >= vec_nums[n_start]) // check in first half;
            b_first_half = true;
        else
            b_first_half = false;
    }
    if (b_first_half)
    {
        n_return_idx = binary_rotate_search(vec_nums, n_start, n_middle_idx, target);
    }
    else
    {
        n_return_idx = binary_rotate_search(vec_nums, n_middle_idx + 1, n_end, target);
    }
    return n_return_idx;
}
/*Private*/
bool updateNode(List *head, List *&pNode, int &nNxtCnt)
{
    if (nNxtCnt == 0)
    {
        return false;
    }
    pNode = head;
    nNxtCnt--;
    return true;
}
List *reverseGroup(List *&pNode, int k, bool &status)
{
    int nLen = k - 1;
    List *pNxtNode = pNode->p_next_;
    pNode->p_next_ = nullptr;
    while (nLen-- > 0)
    {
        if (!swap(pNode, pNxtNode))
        {
            reverseGroup(pNode, k - (nLen + 1), status);
            status = false;
            return nullptr;
        }
    }

    status = true;
    return pNxtNode;
}

struct DPValidAddress
{
    set<string> firstSubset;
    set<string> secondSubset;
    set<string> thirdSubset;
    set<string> forthSubset;
};

/*private*/
void printSubnet(std::set<string> subnet)
{
    for_each(subnet.begin(), subnet.end(), [](string str)
             { std::cout << str << "    "; });
    std::cout << std::endl;
}
/*private*/
void updateNewSubnet(set<string> &vecSubnetUpdate, const set<string> vecNxtSubnet, char ch)
{
    for_each(vecNxtSubnet.begin(), vecNxtSubnet.end(), [&](const string &subnet)
             {
        string str(1,ch);
        string strCheck(str);
        int nIdx = subnet.find('.');
        if(nIdx > 0)
        {
          strCheck.append(subnet.substr(0, nIdx));
        }
        else
        {
          strCheck.append(subnet);
        }
        stringstream stream(strCheck);
        int nSubnet;
        stream >> nSubnet;
        if (nSubnet <= 255)
        {
          str.append(subnet);
          vecSubnetUpdate.insert(str);
        } });
}
/*private*/
void addNewSubnet(set<string> &vecSubnetUpdate, const set<string> &vecDiagSubnet, char ch)
{
    for_each(vecDiagSubnet.begin(), vecDiagSubnet.end(), [&](string subnet)
             {
         string str{ch};
         str.append(".");
         str.append(subnet);
         vecSubnetUpdate.insert(str); });
}
/*private*/
void recuseValidIPAddr(char ch, vector<DPValidAddress> &vecDP, int nIdx)
{
    set<string> vecNxt;
    set<string> vecDiag;
    // populating firstSubset
    {
        vecNxt = vecDP[nIdx + 1].firstSubset;
        updateNewSubnet(vecDP[nIdx].firstSubset, vecNxt, ch);
        // printSubnet(vecDP[nIdx].firstSubset);
    }
    // populating secondSubset
    {
        vecNxt = vecDP[nIdx + 1].secondSubset;
        vecDiag = vecDP[nIdx + 1].firstSubset;
        addNewSubnet(vecDP[nIdx].secondSubset, vecDiag, ch);
        updateNewSubnet(vecDP[nIdx].secondSubset, vecNxt, ch);
        // printSubnet(vecDP[nIdx].secondSubset);
    }
    // populating thirdSubset
    {
        vecNxt = vecDP[nIdx + 1].thirdSubset;
        vecDiag = vecDP[nIdx + 1].secondSubset;
        addNewSubnet(vecDP[nIdx].thirdSubset, vecDiag, ch);
        updateNewSubnet(vecDP[nIdx].thirdSubset, vecNxt, ch);
        // printSubnet(vecDP[nIdx].thirdSubset);
    }
    // populating forthSubset
    {
        vecNxt = vecDP[nIdx + 1].forthSubset;
        vecDiag = vecDP[nIdx + 1].thirdSubset;
        addNewSubnet(vecDP[nIdx].forthSubset, vecDiag, ch);
        updateNewSubnet(vecDP[nIdx].forthSubset, vecNxt, ch);
        // printSubnet(vecDP[nIdx].forthSubset);
    }
}

NodeNxt *connectNxt(NodeNxt *root)
{

    if (root == nullptr)
        return root;
    std::queue<NodeNxt *> pLevelOrderQueue;
    pLevelOrderQueue.push(root);
    pLevelOrderQueue.push(nullptr);
    NodeNxt *pNodeNxt = nullptr;
    while (!pLevelOrderQueue.empty())
    {
        NodeNxt *pPrevNodeNxt = pNodeNxt;
        pNodeNxt = pLevelOrderQueue.front();
        if (pPrevNodeNxt != nullptr)
        {
            pPrevNodeNxt->next = pNodeNxt;
        }
        pLevelOrderQueue.pop();
        if (pNodeNxt != nullptr)
        {
            if (pNodeNxt->left != nullptr)
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
            if (pLevelOrderQueue.size() != 0)
            {
                pLevelOrderQueue.push(nullptr);
            }
        }
    }
    return root;
}

struct info
{
    Node1 *pNode;
    int nLevel;
};
Node1 *connect(Node1 *root)
{
    if (root == nullptr)
        return root;
    std::queue<info> bfs_queue;
    bfs_queue.push({root, 0});
    int nPrev_level = 0;
    Node1 *pPrev_Node = root;
    while (bfs_queue.size() > 0)
    {
        Node1 *pCurr_Node = bfs_queue.front().pNode;
        int nCurr_level = bfs_queue.front().nLevel;
        bfs_queue.pop();

        if (pCurr_Node == root || nCurr_level != nPrev_level)
        {
            pPrev_Node->next = nullptr;
        }
        else
        {
            pPrev_Node->next = pCurr_Node;
        }
        nPrev_level = nCurr_level;
        pPrev_Node = pCurr_Node;
        if (pCurr_Node->left != nullptr)
        {
            bfs_queue.push({pCurr_Node->left, nCurr_level + 1});
            bfs_queue.push({pCurr_Node->right, nCurr_level + 1});
        }
    }
    return root;
}

int count_way_to_reach_stairs(int n_stair_cnt)
{
    if (n_stair_cnt == 0)
        return 0;
    if (n_stair_cnt == 1)
        return 1;
    int *n_way_size = new int[n_stair_cnt + 1];
    n_way_size[0] = 1;
    n_way_size[1] = 1;
    for (int n_stair = 2; n_stair <= n_stair_cnt; ++n_stair)
    {
        n_way_size[n_stair] = n_way_size[n_stair - 1] + n_way_size[n_stair - 2];
    }
    return n_way_size[n_stair_cnt];
}

using type_container = std::vector<std::string>;
void recurse_parantheses(type_container &rVecParantheses, int nSize)
{
    if (nSize == 1)
    {
        rVecParantheses.push_back("()");
        return;
    }
    recurse_parantheses(rVecParantheses, nSize - 1);
    bool bSkip = true;
    size_t nVecSize = rVecParantheses.size();
    for (int i = 0; i < nVecSize; ++i)
    {
        std::string strSubStr = "()";
        if (!bSkip)
            rVecParantheses.push_back(strSubStr + rVecParantheses[i]);
        else
            bSkip = false;
        std::string nxtStr = "(" + rVecParantheses[i] + ")";
        rVecParantheses.push_back(nxtStr);
        rVecParantheses[i] = rVecParantheses[i] + strSubStr;
    }
    //    std::cout << nSize << std::endl;
    for (auto str : rVecParantheses)
        std::cout << str << "  ";
    //   std::cout << std::endl;
}
TreeNode *attachNode(TreeNode *pHead, TreeNode *pLeft, TreeNode *pRight)
{
    TreeNode *pTraverse = pHead;
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
TreeNode *recurseInorder(TreeNode *pTreeNode)
{
    if (pTreeNode == nullptr)
        return nullptr;
    TreeNode *pNode = new TreeNode();
    pNode->val = pTreeNode->val;
    TreeNode *pLeftNode = recurseInorder(pTreeNode->left);
    TreeNode *pRightNode = recurseInorder(pTreeNode->right);
    attachNode(pNode, pLeftNode, pRightNode);

    return pNode;
}

template <typename T>
int find_last_in_complete_binary_tree(Node<T> *p_root, int &n_level)
{
    if (n_level == -1)
    {
        n_level = 0;
        Node<T> *node = p_root;
        while (node->p_left != nullptr)
        {
            n_level++;
            node = node->p_left;
        }
    }
    if (p_root->p_left == nullptr && p_root->p_right == nullptr)
        return p_root->n_info;
    Node<T> *p_node = p_root;
    int n_temp_level = n_level - 1;
    if (check_right_most_is_leaf(p_node->p_left, n_level - 1) == nullptr)
    {
        return find_last_in_complete_binary_tree(p_node->p_left, n_temp_level);
    }
    else
    {
        return find_last_in_complete_binary_tree(p_node->p_right, n_temp_level);
    }
}

int generate_greater_sum(Node<int> *p_node, int n_max_value)
{
    if (p_node == nullptr)
        return n_max_value;
    int n_right_greater = generate_greater_sum(p_node->p_right, n_max_value);
    int new_value = n_right_greater + p_node->n_info;
    p_node->n_info = new_value;
    int n_left_greater = generate_greater_sum(p_node->p_left, p_node->n_info);
    return n_left_greater;
}

/*private*/
void shift_by_idx(std::vector<int> &nums, int nShift, int nShiftStartIdx, int nEnd)
{
    for (int i = nShiftStartIdx; i <= nEnd; i++)
    {
        nums[i - nShift] = nums[i];
    }
}
int removeDublicaateIterate(int nStart, int nShift, vector<int> &nums, int &nShiftStartIdx)
{
    if (nStart >= nums.size())
    {
        return nShift;
    }

    int nShiftNxt = 0;
    nShiftStartIdx = nStart;
    while (nStart < nums.size())
    {
        int nCnt = 1;
        while (nStart + 1 < nums.size() && nums[nStart] == nums[nStart + 1])
        {
            ++nCnt;
            nStart = nStart + 1;
        }
        ++nStart;
        if (nCnt > 2)
        {
            nShiftNxt = nCnt + nShift - 2;
            break;
        }
        else
        {
            nShiftNxt = nShift;
        }
    }
    shift_by_idx(nums, nShift, nShiftStartIdx, nStart - 1);
    return removeDublicaateIterate(nStart, nShiftNxt, nums, nShiftStartIdx);
}

bool GeekSolver::find_triptet_with_zero_sum(const std::vector<int> &vec_input)
{
    bool b_found = false;
    std::unordered_set<int> hash_value;
    std::for_each(vec_input.begin(), vec_input.end(), [&hash_value](int x)
                  { hash_value.insert(x); });
    for (int i_idx = 0; i_idx < vec_input.size() && !b_found; ++i_idx)
    {
        for (int j_idx = 0; j_idx < vec_input.size(); ++j_idx)
        {
            if (j_idx == i_idx)
                continue;
            int sum = -(vec_input[i_idx] + vec_input[j_idx]);
            if (hash_value.find(sum) != hash_value.end())
            {
                b_found = true;
                break;
            }
        }
    }
    return b_found;
}

void GeekSolver::flatten(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *pNode = recurseInorder(root);
    while (pNode->right != nullptr)
    {
        root->left = nullptr;
        root->right = pNode->right;
        root = root->right;
        pNode = pNode->right;
    }
    root->right = nullptr;
}
TreeNode *GeekSolver::sortedListToBST(List *head)
{
    TreeNode *pRetTreeNode = recurseList(head, nullptr);
    return pRetTreeNode;
}

List *GeekSolver::swapPairs(List *head)
{
    List *pNode = head;
    if (pNode != nullptr)
        return swap_adjacent(pNode, pNode->p_next_);
    else
        return pNode;
}

int GeekSolver::my_atoi(const std::string &str_value)
{
    long long n_result_int = 0;
    int b_signed = false;
    std::string str_int_value = str_value;
    int n_length = str_int_value.size();
    int cnt = 0;
    while (str_int_value[cnt++] == ' ' && cnt < n_length)
        ;
    for (int n_idx = cnt - 1; n_idx < n_length; ++n_idx)
    {
        char ch = str_int_value[n_idx];
        if (n_idx == cnt - 1 && ch == 45)
        {
            b_signed = true;
            continue;
        }
        else if (n_idx == cnt - 1 && ch == 43)
        {
            b_signed = false;
            continue;
        }
        if (ch < 48 || ch > 57)
        {
            break;
        }
        n_result_int = n_result_int * 10 + (ch - 48);
        if (n_result_int > INT_MAX)
            return b_signed ? INT_MIN : INT_MAX;
    }
    if (b_signed)
        return -n_result_int;
    else
        return n_result_int;
}

vector<List *> GeekSolver::splitListToParts(List *head, int k)
{
    int nListLen = 0;
    List *pTraverse = head;
    while (pTraverse != nullptr)
    {
        nListLen++;
        pTraverse = pTraverse->p_next_;
    }
    int nSplitListLen = nListLen / k;
    int nSplitListLen_plus_1 = nListLen % k;
    vector<List *> retSplitList;
    pTraverse = head;
    int nNullListCnt = 0;
    if (nListLen < k)
    {
        nNullListCnt = k - nListLen;
    }
    while (pTraverse != nullptr)
    {
        int nLen = nSplitListLen;
        retSplitList.push_back(pTraverse);

        while (pTraverse != nullptr && --nLen > 0)
            pTraverse = pTraverse->p_next_;

        if (nLen == 0 && pTraverse != nullptr && nSplitListLen_plus_1-- > 0)
            pTraverse = pTraverse->p_next_;
        if (pTraverse != nullptr)
        {
            List *pTemp = pTraverse->p_next_;
            pTraverse->p_next_ = nullptr;
            pTraverse = pTemp;
        }
    }
    while (nNullListCnt-- > 0)
    {
        retSplitList.push_back(nullptr);
    }
    return retSplitList;
}

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

vector<int> GeekSolver::shortest_reach(ShortestPathGraph &ref_graph, int start)
{
    std::vector<bool> visited(ref_graph.get_size(), false);
    std::vector<int> distance(ref_graph.get_size(), -1);
    std::queue<int> bft;
    distance[start] = 0;
    visited[start] = true;
    ref_graph.addNebiuour(&bft, start, distance, distance[start], visited);
    while (false == bft.empty())
    {
        int front = bft.front();
        bft.pop();
        if (false == visited[front])
        {
            visited[front] = true;
            ref_graph.addNebiuour(&bft, front, distance, distance[front], visited);
        }
    }

    return distance;
}

int GeekSolver::search(std::vector<int> &nums, int target)
{
    int n_index = binary_rotate_search(nums, 0, nums.size() - 1, target);
    return n_index;
}

List *GeekSolver::rotateList(List *pHead, int k)
{
    List *pTraverseNode = pHead;
    List *pPrevTraverse = nullptr;
    int nNxtCnt = k - 1;
    if (pHead == nullptr || pHead->p_next_ == nullptr || nNxtCnt < 0)
    {
        return pHead;
    }
    while (pTraverseNode->p_next_ != nullptr || updateNode(pHead, pTraverseNode, nNxtCnt))
    {
        if (nNxtCnt > 0)
        {
            nNxtCnt--;
        }
        else
        {
            pPrevTraverse = (pPrevTraverse == nullptr) ? pHead : pPrevTraverse->p_next_;
        }

        pTraverseNode = pTraverseNode->p_next_;
    }
    pTraverseNode->p_next_ = pHead;
    pHead = pPrevTraverse->p_next_;
    pPrevTraverse->p_next_ = nullptr;
    return pHead;
}

void GeekSolver::rotate(std::vector<int> &nums, int k)
{
    if (nums.size() <= k)
        k = k % nums.size();
    int nBckSize = nums.size() - k;
    std::vector<int> vecBck;
    vecBck.reserve(nBckSize);
    for (int nIdx = 0; nIdx < nBckSize; ++nIdx)
    {
        vecBck.push_back(nums[nIdx]);
    }
    for (int nIdx = nBckSize; nIdx < nums.size(); ++nIdx)
    {
        nums[nIdx - nBckSize] = nums[nIdx];
    }
    int nStartIdx = nums.size() - nBckSize;
    for (int nIdx = 0; nIdx < vecBck.size(); ++nIdx)
    {
        nums[nStartIdx] = vecBck[nIdx];
        nStartIdx++;
    }
}

List *GeekSolver::reverseKGroup(List *head, int k)
{
    if (head->p_next_ == nullptr)
        return head;
    bool bKGroup = true;
    List *pNode = head;
    std::queue<List *> queue_StartNode;
    std::queue<List *> queue_EndNode;
    queue_StartNode.push(pNode);
    head = nullptr;
    while (1)
    {
        bool bStatus = false;
        List *pNxtStrtNode = reverseGroup(pNode, k, bStatus);
        if (!bStatus)
        {
            if (head == nullptr)
                head = pNode;
            break;
        }
        if (head == nullptr)
            head = pNode;
        else
            queue_EndNode.push(pNode);
        if (pNxtStrtNode != nullptr)
        {
            queue_StartNode.push(pNxtStrtNode);
            pNode = pNxtStrtNode;
        }
        else
        {
            break;
        }
    }
    while (!queue_EndNode.empty())
    {
        List *start = queue_StartNode.front();
        queue_StartNode.pop();
        if (queue_EndNode.empty())
        {
            start->p_next_ = nullptr;
        }
        else
        {
            start->p_next_ = queue_EndNode.front();
            queue_EndNode.pop();
        }
    }
    while (!queue_StartNode.empty())
    {
        List *start = queue_StartNode.front();
        queue_StartNode.pop();
        if (queue_StartNode.empty())
        {
            start->p_next_ = nullptr;
        }
        else
        {
            start->p_next_ = queue_StartNode.front();
            queue_StartNode.pop();
        }
    }
    return head;
}

List *GeekSolver::reverseBetween(List *head, int left, int right)
{
    List *pPrevLeft = nullptr;
    List *pPrevRight = nullptr;
    List *pTraverseNode = head;
    while (pTraverseNode->p_next_ != nullptr && (pPrevLeft == nullptr || pPrevRight == nullptr))
    {
        if (pPrevLeft == nullptr && pTraverseNode->p_next_->n_value_ == left)
        {
            pPrevLeft = pTraverseNode;
        }
        else if (pPrevRight == nullptr && pTraverseNode->p_next_->n_value_ == right)
        {
            pPrevRight = pTraverseNode->p_next_;
        }
        pTraverseNode = pTraverseNode->p_next_;
    }
    if (pPrevLeft == nullptr || pPrevRight == nullptr)
    {
        return head;
    }
    List *pConnector = pPrevLeft;
    pPrevLeft = pPrevLeft->p_next_;

    // reversing logic
    pTraverseNode = pPrevLeft;
    List *pNext = pTraverseNode->p_next_;
    while (pTraverseNode != pPrevRight)
    {
        List *pTemp = pNext->p_next_;

        // reversing pointer
        pNext->p_next_ = pTraverseNode;

        // shifting pinters
        pTraverseNode = pNext;
        pNext = pTemp;
    }
    pConnector->p_next_ = pPrevRight;
    pPrevLeft->p_next_ = pNext;
    return head;
}

List *GeekSolver::reverseBetween_position(List *head, int left, int right)
{
    List *pPrevLeft = nullptr;
    List *pPrevRight = nullptr;
    List *pTraverseNode = head;
    int nCnt = 1;
    while (pTraverseNode->p_next_ != nullptr)
    {
        nCnt++;
        if (nCnt == left)
        {
            pPrevLeft = pTraverseNode;
        }

        if (nCnt == right)
        {
            pPrevRight = pTraverseNode->p_next_;
            break;
        }
        pTraverseNode = pTraverseNode->p_next_;
    }
    if (pPrevRight == nullptr)
    {
        return head;
    }
    List *pConnector = pPrevLeft;
    // case of pConnector = nullptr;
    if (left == 1)
    {
        pPrevLeft = head;
    }
    else
    {
        pPrevLeft = pPrevLeft->p_next_;
    }
    // reversing logic
    pTraverseNode = pPrevLeft;
    List *pNext = pTraverseNode->p_next_;
    while (pTraverseNode != pPrevRight)
    {
        List *pTemp = pNext->p_next_;

        // reversing pointer
        pNext->p_next_ = pTraverseNode;

        // shifting pinters
        pTraverseNode = pNext;
        pNext = pTemp;
    }

    pPrevLeft->p_next_ = pNext;
    if (pConnector == nullptr)
    {
        return pPrevRight;
    }
    pConnector->p_next_ = pPrevRight;
    return head;
}

int GeekSolver::get_reverse_digit_of_integer(int n_value)
{
    std::cout << "value of integer is " << n_value << std::endl;
    bool b_sign = true;
    if (n_value < 0)
    {
        n_value = -n_value;
        b_sign = false;
    }
    long long n_return_value = 0;
    while (n_value != 0)
    {
        int digit = n_value % 10;
        if (n_return_value * 10 > INT_MAX && b_sign)
        {
            return 0;
        }
        if (n_return_value * 10 > INT_MAX && !b_sign)
        {
            return 0;
        }
        n_return_value = n_return_value * 10 + digit;
        n_value = n_value / 10;
    }
    if (b_sign)
        return n_return_value;
    else
        return -n_return_value;
}

std::set<std::string> GeekSolver::restoreIpAddresses(std::string s)
{
    std::vector<DPValidAddress> vecDP;
    vecDP.resize(s.size());
    string str{s[s.size() - 1]};
    vecDP[s.size() - 1].firstSubset.insert(str);
    for (int nIdx = s.size() - 2; nIdx >= 0; nIdx--)
    {
        recuseValidIPAddr(s[nIdx], vecDP, nIdx);
    }
    return vecDP[0].forthSubset;
}

List *GeekSolver::removeNthFromEnd(List *head, int n)
{
    int nCounter = 0;
    List *pForward = head;
    List *pPrev = head;
    while (pForward != nullptr && nCounter != n)
    {
        pForward = pForward->p_next_;
        nCounter++;
    }
    if (nCounter != n)
    {
        return nullptr;
    }
    else if (pForward != nullptr)
    {
        while (pForward->p_next_ != nullptr)
        {
            pForward = pForward->p_next_;
            pPrev = pPrev->p_next_;
        }
        List *pNode = pPrev->p_next_;
        pPrev->p_next_ = pPrev->p_next_->p_next_;
        delete pNode;
    }
    else
    { // deleteing first node
        if (pPrev->p_next_ == nullptr)
        { // single node case
            delete pPrev;
            return nullptr;
        }
        List *pNode = pPrev;
        head = head->p_next_;
        delete pNode;
    }

    return head;
}

int GeekSolver::removeElement(vector<int> &nums, int val)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int nLastIdx = nums.size() - 1;
    int nStartIdx = 0;
    while (nStartIdx < nLastIdx)
    {
        while (nums[nLastIdx] == val && nStartIdx < nLastIdx)
        {
            nLastIdx--;
        }
        while (nStartIdx < nLastIdx && nums[nStartIdx] != val)
        {
            nStartIdx++;
        }
        if (nStartIdx >= nLastIdx)
        {
            break;
        }

        nums[nStartIdx] = nums[nLastIdx];
        nStartIdx++;
        nLastIdx--;
    }
    if (nums[nLastIdx] == val)
    {
        nLastIdx--;
    }
    return nLastIdx + 1;
}

int GeekSolver::removeDuplicates(vector<int> &nums)
{
    int nStartIdx;
    int nRet = removeDublicaateIterate(0, 0, nums, nStartIdx);
    return nums.size() - nRet;
}

int GeekSolver::removeDuplicatesSorted(std::vector<int> &nums)
{
    int nCnt = 0;
    int nSkipCnt = 0;
    int nNxtIdx = 0;
    while (nCnt < nums.size() - 1)
    {
        int nStartIdx = nCnt;
        while (nCnt < nums.size() - 1 && nums[nCnt] == nums[++nCnt] && ++nSkipCnt)
            ;
        nNxtIdx++;
        nums[nNxtIdx] = nums[nCnt];
    }
    return nums.size() - nSkipCnt;
}

List *GeekSolver::partition_smaller(List *head, int x)
{
    // debug_print(head);
    List *pTraverse = head;
    // Find Node with n_value_ue x
    pTraverse = head;
    List *pPrevTraverse = nullptr;
    List *pListSmaller = nullptr;
    while (pTraverse != nullptr)
    {
        if (pTraverse->n_value_ < x)
        {
            if (pListSmaller == nullptr)
            {
                // case if pTraverse Node is not starting node
                if (pPrevTraverse != nullptr)
                {
                    List *pTemp = pTraverse;
                    pPrevTraverse->p_next_ = pTraverse->p_next_;
                    pTemp->p_next_ = head;
                    head = pTemp;
                }
                pListSmaller = pTraverse;
                pPrevTraverse = pTraverse;
                pTraverse = pTraverse->p_next_;
            }
            else
            {
                if (pPrevTraverse->n_value_ >= x)
                {
                    List *pTemp = pTraverse;
                    pPrevTraverse->p_next_ = pTraverse->p_next_;
                    pTraverse = pPrevTraverse->p_next_;
                    pTemp->p_next_ = pListSmaller->p_next_;
                    pListSmaller->p_next_ = pTemp;
                    pListSmaller = pTemp;
                }
                else
                {
                    pPrevTraverse = pTraverse;
                    pTraverse = pTraverse->p_next_;
                    pListSmaller = pPrevTraverse;
                }
            }
        }
        else
        {
            pPrevTraverse = pTraverse;
            pTraverse = pTraverse->p_next_;
        }
    }
    return head;
}

List *GeekSolver::partition(List *head, int x)
{
    // debug_print(head);
    List *pTraverse = head;
    // Find Node with value x
    List *pNode = nullptr;
    bool bFirstHalf = true;
    while (pTraverse != nullptr)
    {
        if (pTraverse->n_value_ == x)
            break;
        pTraverse = pTraverse->p_next_;
    }
    pNode = pTraverse;
    pTraverse = head;
    List *pListSmaller = nullptr;
    List *pListGratter = pNode;
    while (pTraverse != nullptr)
    {
        if (pTraverse->n_value_ <= x)
        {
            if (bFirstHalf)
            {
                if (pListSmaller == nullptr)
                {
                    pListSmaller = pTraverse;
                    pTraverse = pTraverse->p_next_;
                    continue;
                }
                pListSmaller->p_next_ = pTraverse;
                if (pTraverse->n_value_ == pNode->n_value_)
                {
                    if (pTraverse != pNode)
                    {
                        List *pTemp = pNode->p_next_;
                        pNode->p_next_ = pTraverse;
                        pTraverse = pTraverse->p_next_;
                        pNode = pNode->p_next_;
                        pNode->p_next_ = pTemp;
                    }
                    else
                    {
                        bFirstHalf = false;
                        pTraverse = pListGratter->p_next_;
                    }
                }
                else
                {
                    pListSmaller = pTraverse;
                    pTraverse = pTraverse->p_next_;
                }
            }
            else
            {
                pListSmaller->p_next_ = pTraverse;
                pTraverse = pTraverse->p_next_;
                pListSmaller = pListSmaller->p_next_;
                pListSmaller->p_next_ = pNode;
            }
        }
        else if (pTraverse->n_value_ > x)
        {
            if (!bFirstHalf)
            {
                pListGratter->p_next_ = pTraverse;
                pListGratter = pTraverse;
                pTraverse = pTraverse->p_next_;
            }
            else
            {
                // insert Node in front of pListGratter
                List *pTemp = pListGratter->p_next_;
                pListGratter->p_next_ = pTraverse;
                pTraverse = pTraverse->p_next_;
                pListGratter = pListGratter->p_next_;
                pListGratter->p_next_ = pTemp;
            }
        }
        // we arrive pTraverse == node
        // after this condition change. pTraverse move to other half and
        // all smaller node need to be inserted after pListSmaller and perform jump of pListGratter if we encounter any smaller node
    }
    pListGratter->p_next_ = nullptr;
    return head;
}

int GeekSolver::find_partition_array_into_disjoint_interval(std::vector<int> &input_data)
{
    int n_min_right_val = input_data[input_data.size() - 1];
    int n_max_left_val = input_data[0];
    int n_left_idx = 0;
    int n_right_idx = input_data.size() - 1;
    // switch movement from left to right based on:
    // left switch: any max element in left need to be verified by existance smaller value which is min value in right
    // right switch: any min element in right need to be verified by existance of greter value which in max value in left
    bool b_direction = false;

    while (n_right_idx >= n_left_idx + 1)
    {
        /*if( n_max_left_val < n_min_right_val )
            b_direction = true;
        else
            b_direction = false;
        */
        switch (b_direction)
        {
        case true:
            while (n_min_right_val > input_data[n_left_idx])
            {
                if (n_max_left_val < input_data[n_left_idx])
                    n_max_left_val = input_data[n_left_idx];
                n_left_idx++;
            }
            b_direction = false;
        case false:
            while (n_max_left_val < input_data[n_right_idx])
            {
                if (n_min_right_val > input_data[n_right_idx])
                    n_min_right_val = input_data[n_right_idx];
                n_right_idx--;
            }
            b_direction = true;
        }
    }
    return n_left_idx;
}

std::vector<std::pair<int, int>> GeekSolver::find_pair_with_sum(std::vector<int> &first_array, std::vector<int> &second_array)
{
    std::vector<std::pair<int, int>> vec_result;
    std::sort(first_array.begin(), first_array.end());
    std::sort(second_array.begin(), second_array.end());
    int i = 0;
    int j = second_array.size() - 1;
    for (; i < first_array.size() && j > 0;)
    {
        i++;
        j--;
    }
}

void GeekSolver::create_tree_ptr(const std::vector<int> &vec_data, NodeNxt *&pRoot)
{
    // need to create tree from level-order  traversal
    NodeNxt *pNodeNxt = new NodeNxt(vec_data[0]);
    pRoot = pNodeNxt;
    int height = log2(vec_data.size() + 1);
    int nDepth = 0;
    std::queue<NodeNxt *> queueTree;
    queueTree.push(pNodeNxt);
    while (!queueTree.empty())
    {
        pNodeNxt = queueTree.front();
        queueTree.pop();
        if (pNodeNxt != nullptr && nDepth < height)
        {
            int nLeftIndex = 2 * nDepth + 1;
            int nRightIndex = 2 * nDepth + 2;
            NodeNxt *pLeft = nullptr;
            NodeNxt *pRight = nullptr;
            if (vec_data[nLeftIndex] != -99)
            {
                pLeft = new NodeNxt(vec_data[nLeftIndex]);
            }

            if (vec_data[nRightIndex] != -99)
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

int GeekSolver::minimumJumps(std::vector<int> &forbidden, int a, int b, int x)
{

    std::unordered_map<int, int> map_forbidden;
    for (int i = 0; i < forbidden.size(); i++)
        map_forbidden[forbidden[i]] = 1;
    std::queue<MinJumpinfo> state_queue;
    state_queue.push({0, 0, 0});

    while (!state_queue.empty())
    {
        int cur_pos = state_queue.front().curr;
        int move_cnt = state_queue.front().count;
        bool state = state_queue.front().back_move;
        state_queue.pop();
        if (cur_pos == x)
            return move_cnt;
        if (cur_pos - b >= 0 && state == 0 && map_forbidden[cur_pos - b] == 0)
        {
            state_queue.push({cur_pos - b, 1, move_cnt + 1});
            map_forbidden[cur_pos - b] = 1;
        }
        if (cur_pos + a < 500 && map_forbidden[cur_pos + a] == 0)
        {
            state_queue.push({cur_pos + a, 0, move_cnt + 1});
            map_forbidden[cur_pos + a] = 1;
        }
    }
    return -1;
}

// dp to choose from making solution with increading zero's and increasing one's
//  solution d(i) = min{ d1(i -1) , d0(i -1) }

int GeekSolver::min_flip_monotone_increasing(const std::string &input_string)
{
    int n_size = input_string.size();
    std::vector<int> dp0;
    dp0.reserve(n_size);
    std::vector<int> dp1;
    dp1.reserve(n_size);
    if (input_string[0] == '0')
    {
        dp1[0] = 1;
        dp0[0] = 0;
    }
    else
    {
        dp1[0] = 0;
        dp0[0] = 1;
    }

    for (int n_idx = 1; n_idx < n_size; ++n_idx)
    {
        if (input_string[n_idx] == '0')
        {
            dp0[n_idx] = dp0[n_idx - 1];
            dp1[n_idx] = std::min(dp0[n_idx - 1] + 1, dp1[n_idx - 1] + 1);
        }
        else
        {
            dp0[n_idx] = dp0[n_idx - 1] + 1;
            dp1[n_idx] = std::min(dp1[n_idx - 1], dp0[n_idx - 1]);
        }
    }
    return (std::min(dp1[n_size - 1], dp0[n_size - 1]));
}

void GeekSolver::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    if (n == 0)
    {
        return;
    }
    if (m == 0)
    {
        nums1 = nums2;
    }
    int nLeftIdx = m - 1;
    int nRightIdx = n - 1;
    int nFinalIdx = m + n - 1;
    while (nLeftIdx >= 0 && nRightIdx >= 0)
    {
        if (nums1[nLeftIdx] <= nums2[nRightIdx])
        {
            nums1[nFinalIdx] = nums2[nRightIdx];
            nRightIdx--;
        }
        else
        {
            nums1[nFinalIdx] = nums1[nLeftIdx];
            nLeftIdx--;
        }
        nFinalIdx--;
    }
    while (nRightIdx >= 0)
    {
        nums1[nFinalIdx] = nums2[nRightIdx];
        nRightIdx--;
        nFinalIdx--;
    }
}

vector<vector<int>> GeekSolver::merge(vector<vector<int>> &intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y)
              { return x[0] < y[0]; });
    vector<vector<int>> returnVec;
    vector<int> interval = intervals[0];
    auto it = intervals.begin();
    ++it;
    bool bIntervalEnd = false;
    while (true)
    {
        if (it == intervals.end())
        {
            returnVec.push_back(interval);
            break;
        }
        if (interval[1] >= (*it)[0])
        {
            if (interval[1] <= (*it)[1])
            {
                interval[1] = (*it)[1];
            }
            else
            {
                ++it;
                continue;
            }
        }
        else
        {

            returnVec.push_back(interval);
            interval = *it;
        }
        ++it;
    }
    return returnVec;
}

double GeekSolver::findMedianSortedArrays(std::vector<int> &nums_x, std::vector<int> &nums_y)
{
    int nStart_x, nStart_y = 0;
    int nEnd_x = nums_x.size() - 1;
    int nEnd_y = nums_y.size() - 1;
    int nMedianIdx = (nEnd_x + nEnd_y + 1) / 2;
    int x1, x2, y1, y2;
    int nMedian = 0;
    bool bFound = false;
    while (!bFound)
    {
        int nMid_x = (nEnd_x - nStart_x) / 2;
        x1 = nums_x[nMid_x];
        x2 = nums_x[nMid_x + 1];
        int nMid_y = nMedianIdx - nMid_x - 1;
        y1 = nums_x[nMid_y];
        y2 = nums_x[nMid_y + 1];

        if (x1 <= y2 && y1 <= x2)
        {
            if ((nEnd_x + nEnd_y) % 2 != 0)
            {
                if (y1 > y2)
                    nMedian = y2;
                else
                    nMedian = y1;
            }
            else
            {
                nMedian = (y2 + y1) / 2;
            }
            bFound = true;
        }
        else if (x1 > y2)
        {
            nEnd_x = nMid_x;
        }
        else // y1 > x2
        {
            nStart_x = nMid_x + 1;
        }
    }
    return nMedian;
}

int GeekSolver::maxSubArray(vector<int> &nums)
{
    int nSum = 0;
    int nMaxSum = 0;
    for (auto nVal : nums)
    {
        nSum += nVal;
        if (nSum > nMaxSum)
        {
            std::cout << "updated value " << nSum << std::endl;
            nMaxSum = nSum;
        }
        if (nSum < 0)
        {
            std::cout << "reset " << nSum << std::endl;
            nSum = 0;
        }
    }
    return nMaxSum;
}

int GeekSolver::find_max_index(std::vector<int> vec_input)
{
    int n_start_idx = 0;
    int n_end_idx = vec_input.size() - 1;
    int n_start = vec_input[n_start_idx];
    int n_end = vec_input[n_end_idx];
    int result = 0;
    while (n_start_idx < n_end_idx)
    {
        if (vec_input[n_end_idx] >= vec_input[n_start_idx])
            break;
        n_end_idx--;
    }
    n_start_idx = n_start_idx + 1;
    result = n_end_idx;
    while (n_start_idx + result < vec_input.size())
    {
        n_end_idx = n_start_idx + result;
        for (int idx = vec_input.size() - 1; idx > n_end_idx; --idx)
        {
            if (vec_input[idx] >= vec_input[n_start_idx])
            {
                if (result < idx - n_start_idx)
                    result = idx - n_start_idx;
                break;
            }
        }
        n_start_idx++;
    }
    return result;
}

int GeekSolver::maxSubarraySumCircular(std::vector<int> &nums)
{
    int nIdx = 0;
    int nSum = 0;
    int nMaxSum = 0;
    int nMax = 0;
    int nMinSum = 0;
    int nMin = 0;
    nSum = nMin = nMinSum = nMax = nMaxSum = nums[0];
    nIdx++;
    while (nIdx < nums.size())
    {
        nMaxSum = std::max(nMaxSum + nums[nIdx], nums[nIdx]);
        nMax = std::max(nMax, nMaxSum);

        nMinSum = std::min(nMinSum + nums[nIdx], nums[nIdx]);
        nMin = std::min(nMin, nMinSum);

        nSum += nums[nIdx];
        ++nIdx;
    }

    int nCircularMax = nSum - nMin;
    if (nMax < nCircularMax)
    {
        nMax = nCircularMax;
    }
    return nMax;
}

int GeekSolver::maxProfit(std::vector<int> &prices)
{
    int nBuyIdx = 0;
    int nProfit = 0;
    int nSellIdx = 0;
    bool bProfitCal = false;
    for (int nIdx = 1; nIdx < prices.size(); ++nIdx)
    {
        if (prices[nIdx] > prices[nSellIdx])
        {
            nSellIdx = nIdx;
            bProfitCal = true;
        }
        else
        {
            // std::cout << "nSell Price " << prices[nSellIdx] << " nBuy Price " << prices[nBuyIdx] << std::endl;
            nProfit += prices[nSellIdx] - prices[nBuyIdx];
            nSellIdx = nBuyIdx = nIdx;
            bProfitCal = false;
        }
    }
    if (bProfitCal && prices[nSellIdx] > prices[nBuyIdx])
    {
        nProfit += prices[nSellIdx] - prices[nBuyIdx];
    }
    return nProfit;
}

int GeekSolver::maxProfitOnce(std::vector<int> &prices)
{
    int nMinPrice = prices[0];
    int nProfit = 0;
    for (int nIdx = 1; nIdx < prices.size(); ++nIdx)
    {
        if (prices[nIdx] > nMinPrice)
        {
            nProfit = prices[nIdx] - nMinPrice > nProfit ? prices[nIdx] - nMinPrice : nProfit;
        }
        else
        {
            nMinPrice = prices[nIdx];
        }
    }
    return nProfit;
}

int GeekSolver::majorityElement(std::vector<int> &nums)
{
    int nCount = 0;
    int nElement = 0;
    for (int nIdx = 0; nIdx < nums.size(); ++nIdx)
    {
        if (nCount == 0)
        {
            nElement = nums[nIdx];
            nCount = 1;
            continue;
        }

        if (nums[nIdx] == nElement)
        {
            nCount++;
        }
        else
        {
            nCount--;
        }
    }
    return nElement;
}

struct ListNode
{
    int n_value_;
    int key;
    ListNode *p_next_;
    ListNode(int key_, int value_) : key(key_), n_value_(value_)
    {
    }
};

int GeekSolver::find_longest_valid_parantheses(const std::string &input_string)
{
    std::stack<int> stack_parantheses;
    int n_longest_parantheses = 0;
    for (int idx = 0; idx < input_string.size(); ++idx)
    {
        if (input_string[idx] == '(')
        {
            stack_parantheses.push(idx);
        }
        else
        {
            if (stack_parantheses.empty() || stack_parantheses.top() < 0)
            {
                int neg_idx = -idx;
                stack_parantheses.push(neg_idx);
            }
            else
            {
                int start_idx = stack_parantheses.top();
                stack_parantheses.pop();

                if (!stack_parantheses.empty() && stack_parantheses.top() > 0)
                {
                    int prev_paran_idx = stack_parantheses.top();

                    if (prev_paran_idx != start_idx - 1)
                        start_idx = prev_paran_idx + 1;
                }
                if (idx - start_idx > n_longest_parantheses)
                {
                    n_longest_parantheses = idx - start_idx;
                }
            }
        }
    }
    return n_longest_parantheses + 1;
}

int GeekSolver::lengthOfLongestSubstring(std::string s)
{
    std::map<char, int> setChar;
    int nLongestLen = 0;
    int nSubStrlen = 0;
    int nIdx = 0;
    int nStartIdx = 0;
    for (auto ch : s)
    {
        auto it = setChar.find(ch);
        if (it != setChar.end())
        {
            int nIndex = it->second;
            if (nStartIdx <= nIndex)
            {
                nSubStrlen = nIdx - nIndex;
                nStartIdx = nIndex;
            }
            else
            {
                nSubStrlen++;
            }
            setChar[ch] = nIdx;
        }
        else
        {
            nSubStrlen++;
            setChar.insert(std::make_pair(ch, nIdx));
        }
        if (nSubStrlen > nLongestLen)
        {
            nLongestLen = nSubStrlen;
        }
        nIdx++;
    }
    return nLongestLen;
}

static std::vector<std::string> listPhonicNumber = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// std::vector<std::string> recurse_nxt_digit(int nDigit_Idx,const std::string& rStrDigit);
std::vector<std::string> GeekSolver::letter_combination_of_phone_number(const std::string &rStrDigit)
{
    int nDigit_idx = 0;
    return recurse_nxt_digit(nDigit_idx, rStrDigit);
}

std::vector<std::string> GeekSolver::recurse_nxt_digit(int nDigit_Idx, const std::string &rStrDigit)
{
    std::vector<std::string> vecStrList;
    if (rStrDigit == "")
        return vecStrList;
    char chDigit = rStrDigit[nDigit_Idx];

    int n_digit = chDigit - '0'; // convert ch_digit to n_digit;
    std::string strPhonic = listPhonicNumber[n_digit];
    if (nDigit_Idx == rStrDigit.size() - 1)
    {
        for (int i = 0; i < strPhonic.size(); ++i)
            vecStrList.push_back(std::string(1, strPhonic[i]));
        return vecStrList;
    }
    std::vector<std::string> vec_retList;
    vecStrList = recurse_nxt_digit(nDigit_Idx + 1, rStrDigit);
    for (int i = 0; i < strPhonic.size(); ++i)
    {
        for (auto it = vecStrList.begin(); it != vecStrList.end(); ++it)
        {
            vec_retList.push_back(strPhonic[i] + *it);
        }
    }
    return vec_retList;
}

std::vector<int> GeekSolver::find_jumping_number_list(int n_input)
{
    std::vector<int> vec_result;
    std::queue<int> generator_queue;
    vec_result.push_back(0);
    for (int i = 1; i <= 9 && i < n_input; ++i)
    {
        generator_queue.push(i);
        vec_result.push_back(i);
    }
    bool bflag = false;
    for (int i = 0; bflag == false; ++i)
    {
        std::queue<int> temp_queue;
        while (!generator_queue.empty())
        {
            int num = generator_queue.front();

            generator_queue.pop();
            int n_rem = num % 10;
            int new_num;
            if (n_rem != 0)
            {
                new_num = num * 10 + n_rem - 1;
                if (new_num > n_input)
                {
                    bflag = true;
                    break;
                }
                vec_result.push_back(new_num);
                temp_queue.push(new_num);
            }
            if (n_rem != 9)
            {
                new_num = num * 10 + n_rem + 1;
                if (new_num > n_input)
                {
                    bflag = true;
                    break;
                }
                vec_result.push_back(new_num);
                temp_queue.push(new_num);
            }
        }
        generator_queue = temp_queue;
    }
    return vec_result;
}

int GeekSolver::jump(std::vector<int> &nums)
{
    std::vector<int> arrMove;
    if (nums.size() == 1)
    {
        return 0;
    }

    for (auto it : nums)
    {
        arrMove.push_back(0);
    }
    arrMove[0] = 0;

    for (int i = 0; i < arrMove.size(); ++i)
    {
        if (i != 0 && (arrMove[i] == 0 || arrMove[i] > arrMove[i - 1] + 1))
        {
            arrMove[i] = arrMove[i - 1] + 1;
        }

        int jump = nums[i];
        for (int k = 1; k <= jump; ++k)
        {
            if (i + k > nums.size() - 1)
            {
                continue;
            }

            if (arrMove[i + k] == 0 || arrMove[i + k] > arrMove[i] + 1)
            {
                arrMove[i + k] = arrMove[i] + 1;
            }
        }
    }

    return arrMove[nums.size() - 1];
}

std::vector<int> GeekSolver::grayCode(int n)
{
    std::vector<int> vec_GrayCode(pow(2, n), 0);
    vec_GrayCode[0] = 0;
    vec_GrayCode[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        int nCnt = pow(2, i);
        int nBackIdx = (nCnt) / 2 - 1;
        for (int idx = (nCnt) / 2; idx < nCnt; idx++)
        {
            vec_GrayCode[idx] = pow(2, i - 1) + vec_GrayCode[nBackIdx];
            nBackIdx--;
        }
    }
    return vec_GrayCode;
}

int swap(int n, vector<vector<int>> &matrix, int nRow, int nCol)
{
    int nRet = matrix[nRow][nCol];
    matrix[nRow][nCol] = n;
    return nRet;
}

void GeekSolver::rotate(std::vector<std::vector<int>> &matrix)
{
    int nLeft, nTop = 0;
    int nRight, nBottom = matrix.size() - 1;
    while (nLeft < nRight)
    {
        int i = nLeft;
        while (i < nRight)
        {
            int nTemp = matrix[nTop][nLeft + i];
            nTemp = swap(nTemp, matrix, nTop + i, nRight);
            nTemp = swap(nTemp, matrix, nBottom, nRight - i);
            nTemp = swap(nTemp, matrix, nBottom - i, nLeft);
            nTemp = swap(nTemp, matrix, nTop, nLeft + i);
            i++;
        }
        nLeft++;
        nRight--;
        nTop++;
        nBottom++;
    }
}

std::vector<std::string> generateParenthesis(int n)
{
    type_container result_parantheses;
    recurse_parantheses(result_parantheses, n);
    return result_parantheses;
}

std::tuple<int, int> GeekSolver::find_subarray_with_given_sum(std::vector<int> vec_input, int n_sum)
{
    int n_start_idx = 0;
    int n_end_idx = 0;
    int n_temp_sum = vec_input[n_start_idx];
    bool b_found = false;

    while (n_end_idx < vec_input.size() - 1)
    {
        if (n_temp_sum == n_sum)
        {
            b_found = true;
            break;
        }
        if (n_start_idx == n_end_idx || n_temp_sum < n_sum)
        {
            n_end_idx++;
            n_temp_sum += vec_input[n_end_idx];
        }
        else
        {
            n_temp_sum -= n_start_idx;
            n_start_idx--;
        }
    }

    if (b_found)
        return std::make_tuple(n_start_idx, n_end_idx);
    else
        return std::make_tuple(-1, -1);
}

// namespace app
//{
// input List is zagged array of list
std::tuple<int, int> GeekSolver::find_smallest_range(int nList_cnt, List **pplist_collection)
{
    std::vector<List *> current_Heap;
    unsigned int nStartIdx, nEndIndex;
    unsigned int n_max = 0;
    unsigned int nDiff_result = 10000;

    for (int idx = 0; idx < nList_cnt; ++idx)
    {
        current_Heap.push_back(pplist_collection[idx]);
        if (pplist_collection[idx]->n_value_ > n_max)
            n_max = pplist_collection[idx]->n_value_;
    }
    std::make_heap(current_Heap.begin(), current_Heap.end(), [](List *x, List *y)
                   { return x->n_value_ > y->n_value_; });
    // finding minimum element
    List *pMinList = current_Heap.front();
    while (1)
    {

        /*std::cout << " min element value " << pMinList->n_value_ <<std::endl;
        std::for_each(current_Heap.begin(), current_Heap.end(), [](List* pList){
                std::cout << "heap data is " << pList->n_value_<< std::endl;
                });
        */
        // removing min element
        std::pop_heap(current_Heap.begin(), current_Heap.end());
        current_Heap.pop_back();

        if (pMinList->p_next_ == nullptr)
            break;
        List *element = pMinList->p_next_;
        // adding element in heap
        current_Heap.push_back(element);
        // hippifying the heap with new element added at the back
        std::make_heap(current_Heap.begin(), current_Heap.end(), [](List *x, List *y)
                       { return x->n_value_ > y->n_value_; });

        // updating new minimum element
        pMinList = current_Heap.front();
        // upating elment_value to new arr_number
        if (element->n_value_ > n_max)
        {
            n_max = element->n_value_;
        }
        // update min of the new heap
        if ((n_max - pMinList->n_value_) < nDiff_result)
        {
            nDiff_result = n_max - pMinList->n_value_;
            nStartIdx = pMinList->n_value_;
            nEndIndex = n_max;
            // std::cout << "min_elemt is " << nStartIdx << " max element is "<< nEndIndex << " diffence is " << nDiff_result << std::endl;
        }
    }

    return {nStartIdx, nEndIndex};
}

//}

std::vector<int> GeekSolver::find_sets_with_last_occurance(std::vector<char> vec_occurance)
{
    std::vector<int> vec_result;
    std::vector<int> vec_start;
    vec_start.reserve(26);
    std::vector<int> vec_end;
    vec_end.reserve(26);
    int n_idx = 0;
    while (n_idx < vec_occurance.size())
    {
        vec_end[vec_occurance[n_idx] - 97] = n_idx;
        n_idx++;
    }
    int n_max = vec_end[vec_occurance[0] - 97];
    int n_start = 0;
    int n_nxt = 1;
    while (n_nxt < vec_occurance.size())
    {
        while (n_nxt < n_max)
        {
            if (vec_end[vec_occurance[n_nxt] - 97] > n_max)
            {
                n_max = vec_end[vec_occurance[n_nxt] - 97];
            }
            n_nxt++;
        }
        vec_result.push_back(n_max - n_start);
        n_start = n_nxt + 1;
        n_max = vec_end[vec_occurance[n_start] - 97];
        n_nxt++;
    }
}

// find minimum positive element missing in the unsorted array with positive and
// negative elements
// arr [ 4, -2, 5, 2, 10, -7, -6, 1]
// output : 3
// time complexity: ( n );
// space complexity: ( 1 );
int GeekSolver::find_min_number_from_given_sequence(int n_size, int *p_arr)
{
    int n_left_idx = 0;
    int n_right_idx = n_size - 1;
    while (n_right_idx != n_left_idx)
    {
        while (p_arr[n_left_idx] > 0 && n_right_idx - n_left_idx > 0)
            n_left_idx++;
        while (p_arr[n_right_idx] < 0 && n_right_idx - n_left_idx > 0)
            n_right_idx--;
        if (n_right_idx != n_left_idx)
        {
            // swap elements
            int temp = p_arr[n_left_idx];
            p_arr[n_left_idx] = p_arr[n_right_idx];
            p_arr[n_right_idx] = temp;
        }
    }
    // for( int n_index = 0 ; n_index < n_size; ++n_index )
    //     std::cout << "values after shifting negative" << p_arr[ n_index ] << std::endl;
    int n_start = 0;
    int n_end = n_left_idx;
    for (int n_cnt = n_start; n_cnt < n_end; ++n_cnt)
    {
        if (p_arr[abs(p_arr[n_cnt]) - 1] > 0)
        {
            p_arr[abs(p_arr[n_cnt]) - 1] = -p_arr[abs(p_arr[n_cnt]) - 1];
        }
    }
    int res_min = -1;
    while (n_start <= n_end)
    {
        if (p_arr[n_start] > 0)
        {
            res_min = n_start;
            break;
        }
        n_start++;
    }

    // for( int n_index = 0 ; n_index < n_size; ++n_index )
    //   std::cout << "values after hashing" << p_arr[ n_index ] << std::endl;
    return res_min + 1;
}

int GeekSolver::find_max_area(const std::vector<int> &heights)
{
    int nStartIdx = 0;
    int nEndIdx = heights.size() - 1;
    int nMaxArea = 0;
    while (nStartIdx < heights.size() - 1 && nEndIdx > 0 && nStartIdx < nEndIdx)
    {
        int nArea = std::min(heights[nStartIdx], heights[nEndIdx]) * (nEndIdx - nStartIdx);
        if (nMaxArea < nArea)
            nMaxArea = nArea;
        if (heights[nStartIdx] < heights[nEndIdx])
            nStartIdx++;
        else
            nEndIdx--;
    }
    return nMaxArea;
};
template <typename T>
Node<T> *add_next_node(Node<T> *p_node, T n_value)
{
    Node<T> *p_child = new Node(n_value);
    if (p_node->p_left == nullptr)
        p_node->p_left = p_child;
    else
        p_node->p_right = p_child;
    return p_child;
}

template <typename T>
void GeekSolver::create_complete_binary_tree(const std::vector<T> &vec_input)
{
    std::queue<Node<T> *> level_queue;
    std::queue<Node<T> *> nxt_level_queue;
    Node<T> *p_root = new Node(vec_input[0]);
    level_queue.push(p_root);
    Node<T> *p_parent;
    bool b_left_orient = true;
    for (int i = 1; i < vec_input.size(); ++i)
    {
        if (b_left_orient == false)
        {
            if (level_queue.empty())
                level_queue = nxt_level_queue;
            p_parent = level_queue.front();
            level_queue.front();
        }
        Node<T> *p_child_node = add_next_node(p_parent, vec_input[i]);
        nxt_level_queue.push(p_child_node);
        b_left_orient != b_left_orient;
    }
}

template <typename T>
Node<T> *check_right_most_is_leaf(Node<T> *p_node, int n_level)
{
    while (p_node->p_right != nullptr)
    {
        p_node = p_node->p_right;
        n_level--;
    }
    if (n_level == 0)
        return p_node->p_right;
    else
        return nullptr;
}

int recurse_to_find_start_idx(int *arr, int n_start, int n_end)
{
    int n_return_idx = -1;
    // array is already sorted
    if (n_start == n_end)
        return -1;
    int n_mid = n_start + (n_end - n_start) / 2;
    if (arr[n_mid] > arr[n_mid + 1])
        return n_mid + 1;
    if (n_mid != n_start && arr[n_mid] < arr[n_mid - 1])
        return n_mid;

    if (arr[n_start] > arr[n_mid])
        n_return_idx = recurse_to_find_start_idx(arr, n_start, n_mid);
    else
        n_return_idx = recurse_to_find_start_idx(arr, n_mid + 1, n_end);

    return n_return_idx;
}
int GeekSolver::find_first_in_rotated_sorted_array(int *arr, int nSize)
{
    int n_start = 0;
    int n_end = nSize - 1;
    return recurse_to_find_start_idx(arr, n_start, n_end);
}

int binary_search(const std::vector<int> &vec_input, int n_start, int n_end, int target)
{
    if (target == vec_input[n_start])
        return n_start;
    if (target == vec_input[n_end])
        return n_end;
    if (n_start == n_end)
        return -1;
    int n_mid_idx = n_start + (n_end - n_start) / 2;
    if (target == vec_input[n_mid_idx])
        return n_mid_idx;
    if (target < vec_input[n_mid_idx])
        return binary_search(vec_input, n_start, n_mid_idx, target);
    else
        return binary_search(vec_input, n_mid_idx + 1, n_end, target);
}
std::vector<int> GeekSolver::searchRange(std::vector<int> &nums, int target)
{
    std::vector<int> ret_vec = {-1, -1};
    if (nums.size() == 0)
        return ret_vec;
    if (nums.size() == 1 && nums[0] == target)
    {
        ret_vec[0] = ret_vec[1] = 0;
        return ret_vec;
    }
    int n_end = nums.size() - 1;

    int return_idx;
    if (target < nums[0] || target > nums[n_end])
        return_idx = -1;
    return_idx = binary_search(nums, 0, n_end, target);
    int n_start_idx = return_idx;
    while (n_start_idx - 1 >= 0 && nums[n_start_idx - 1] == target)
        n_start_idx--;
    ret_vec[0] = n_start_idx;
    while (return_idx + 1 <= n_end && nums[return_idx + 1] == target)
        return_idx++;
    ret_vec[1] = return_idx;
    return ret_vec;
}
bool GeekSolver::dfs_check_loop(int nIndex, std::vector<bool> &arrVisited, const std::vector<int> &arrCircular, int &nLoopLen, bool bSign)
{
    if (arrVisited[nIndex] == true)
    {
        if (nLoopLen > 1)
            return true;
        else
            return false;
    }
    nLoopLen++;
    int nMove = arrCircular[nIndex];
    arrVisited[nIndex] = true;
    int newIndex = nIndex + nMove;
    if (newIndex < 0)
    {
        newIndex = arrCircular.size() + newIndex;
    }
    if (newIndex > (arrCircular.size() - 1))
    {
        newIndex %= arrCircular.size();
    }
    if ((arrCircular[newIndex] > 0) == (bSign) && newIndex != nIndex)
    {
        return dfs_check_loop(newIndex, arrVisited, arrCircular, nLoopLen, bSign);
    }
    else
    {
        return false;
    }
    return false;
}

bool GeekSolver::check_circular_loop(std::vector<int> &arrCircular)
{
    std::vector<bool> arrVisited;
    for (int i = 0; i < arrCircular.size(); ++i)
        arrVisited.push_back(false);
    for (int i = 0; i < arrCircular.size(); ++i)
    {
        if (arrVisited[i] == false)
        {
            int nLoopLen = 0;
            bool bSign = arrCircular[i] > 0 ? true : false;
            if (dfs_check_loop(i, arrVisited, arrCircular, nLoopLen, bSign))
            {
                return true;
            }
            else
            {
                for (int i = 0; i < arrCircular.size(); ++i)
                    arrVisited[i] = false;
            }
        }
    }
    return false;
}

std::vector<int> GeekSolver::find_duplicate_in_n_time(int n_size, int *p_arr)
{
    std::vector<int> vec_result;
    for (int n_index = 0; n_index < n_size; ++n_index)
    {
        if (p_arr[abs(p_arr[n_index])] < 0)
            vec_result.push_back(abs(p_arr[n_index]));
        else
            p_arr[abs(p_arr[n_index])] = -p_arr[abs(p_arr[n_index])];
    }
    return vec_result;
}

bool GeekSolver::dfs(Node<char> *p_node, std::set<std::string> &set_sub_tree_matcher)
{
    if (p_node == nullptr)
        return false;
    if (p_node->p_left != nullptr && p_node->p_right != nullptr)
    {
        std::string str_sub_tree;
        str_sub_tree.push_back(p_node->p_left->n_info);
        str_sub_tree.push_back(p_node->n_info);
        str_sub_tree.push_back(p_node->p_left->n_info);
        if (set_sub_tree_matcher.find(str_sub_tree) != set_sub_tree_matcher.end())
        {
            std::cout << "matching string is " << str_sub_tree << std::endl;
            return true;
        }
        else
        {
            set_sub_tree_matcher.insert(str_sub_tree);
        }
    }
    return dfs(p_node->p_left, set_sub_tree_matcher) || dfs(p_node->p_right, set_sub_tree_matcher);
}

bool GeekSolver::check_duplicate_sub_tree(Node<char> *p_root)
{
    std::set<std::string> set_sub_tree_matcher;
    // aply dfs on binary_tree
    return dfs(p_root, set_sub_tree_matcher);
}

bool checkIfExist(std::string &s, int nIndex, const std::set<char> &setDistinct)
{
    if (setDistinct.find(s[nIndex]) != setDistinct.end())
    {
        return false;
    }
    return true;
}
int GeekSolver::countGoodSubstrings(std::string s)
{
    if (s.size() < 3)
        return 0;
    int nSlidingIndex = 0;
    int nCountDistinct = 0;

    for (; nSlidingIndex < s.size() - 2; ++nSlidingIndex)
    {
        set<char> setDistinct;
        setDistinct.insert(s[nSlidingIndex]);
        if (!checkIfExist(s, nSlidingIndex + 1, setDistinct))
            continue;
        setDistinct.insert(s[nSlidingIndex + 1]);
        if (!checkIfExist(s, nSlidingIndex + 2, setDistinct))
            continue;
        nCountDistinct++;
    }
    return nCountDistinct;
}

List *GeekSolver::reverse(List *p_root)
{
    if (p_root == nullptr)
        return nullptr;
    if (p_root->p_next_ == nullptr)
        return p_root;
    List *p_prev_node = p_root;
    List *p_temp_node = p_root->p_next_;
    while (p_temp_node != nullptr)
    {
        List *nxt_ptr = p_temp_node->p_next_;
        p_temp_node->p_next_ = p_prev_node;
        p_prev_node = p_temp_node;
        p_temp_node = nxt_ptr;
    }
    p_root->p_next_ = nullptr;
    return p_prev_node;
}
List *GeekSolver::delete_node_with_greater_on_right(List *p_List)
{
    // reversing link List
    List *p_reverse_list = reverse(p_List);
    List *p_temp_node = p_reverse_list;
    int n_max = p_temp_node->n_value_;
    while (p_temp_node->p_next_ != nullptr)
    {
        if (p_temp_node->p_next_->n_value_ > n_max)
        {
            n_max = p_temp_node->p_next_->n_value_;
            p_temp_node = p_temp_node->p_next_;
        }
        else
        {
            List *p_node = p_temp_node->p_next_;
            p_temp_node->p_next_ = p_temp_node->p_next_->p_next_;
            delete p_node;
        }
    }
    p_reverse_list = reverse(p_reverse_list);
    return p_reverse_list;
}

/*
std::string GeekSolver::countOfAtoms(std::string formula)
{
  std::map<char, int>
  std::stack<char> stackChar;
  for (auto iter = formula.begin(); iter != formula.end(); ++iter)
  {
    char cFormula = *iter;
    switch (cFormula)
    {
      case '(':
      {
        stackChar.push('(');
        break;
      }
      case ')':
      {
        if (isdigit(*(iter + 1))
        {
            iter++;
            int nCnt = char_to_int(*iter);
            std::stack<char> stachChar_temp;
            while (stackChar.front() != '(')
            {
               char nextChar = stackChar.front();
               int nAtomCnt = nCnt;
               if (!isalpha(nextChar))
               {
                  stackChar.pop();
                  int nPrevCnt =  char_to_int(nextChar);
                  nextChar = stackChar.front();
                  nAtomCnt = nAtomCnt * nPrevCnt;
               }
               else
               {

               }
               stackChar_temp.push(nAtomCnt);
            }
            stackChar.pop();
        }
        else
        {

        }

        break;
      }
      default:
      {
        if (isalpha(cFormula)) // its a character
        {
          if (!stackChar.empty())
          {
            stackChar.push(cFormula);
          }
        }
        if () //its a character
      }
    }
  }
}
*/
std::string GeekSolver::countAndSay(int n)
{
    std::string str_count_and_say;
    std::vector<int> vec_result;
    vec_result.push_back(1);
    for (int i = 1; i < n; ++i)
    {
        int nNxtIdx = 1;
        std::vector<int> nxt_vec;
        auto iter = vec_result.begin();
        while (iter + 1 != vec_result.end())
        {
            if (*iter != *(iter + 1))
            {
                nxt_vec.push_back(nNxtIdx);
                nxt_vec.push_back(*iter);
                nNxtIdx = 1;
            }
            else
            {
                nNxtIdx++;
            }
            ++iter;
        }
        nxt_vec.push_back(nNxtIdx);
        nxt_vec.push_back(*iter);
        vec_result = nxt_vec;
    }
    for (auto iter = vec_result.begin(); iter != vec_result.end(); ++iter)
    {
        char ch = '0' + *iter;
        str_count_and_say.push_back(ch);
    }
    return str_count_and_say;
}

template <typename T>
Node_with_nxt_right<T> *GeekSolver::connect_node_at_same_level(Node_with_nxt_right<T> *p_node)
{
    // updated BSF using queue
    std::queue<std::pair<Node_with_nxt_right<T> *, int>> node_queue;
    node_queue.push(std::make_pair(p_node, 0));
    Node_with_nxt_right<T> *p_nxt_node = nullptr;
    int n_current_level = 0;
    while (node_queue.empty())
    {
        std::pair<Node_with_nxt_right<T> *, int> node_pair = node_queue.front();
        Node_with_nxt_right<T> *node = node_pair.first;
        int n_level = node_pair.second;
        if (n_level != n_current_level)
        {
            n_current_level = n_level;
            node->p_next_right_ = nullptr;
            n_current_level++;
        }
        else
        {
            node->p_next_right_ = p_nxt_node->p_node_;
            p_nxt_node = node;
        }

        node_queue.pop();
        if (node->get_left() != nullptr)
            node_queue.push(std::make_pair((Node_with_nxt_right<T> *)(node->get_left()), n_level + 1));
        if (node->get_right() == nullptr)
            node_queue.push(std::make_pair((Node_with_nxt_right<T> *)(node->get_right()), n_level + 1));
    }
    return p_node;
}

bool GeekSolver::check_larry_array(std::vector<int> vecInputArray)
{
    int nShiftReq = 0;
    for (int i = 0; i < vecInputArray.size(); ++i)
    {
        int value = vecInputArray[i];
        int index = i + 1;
        if (value == index)
            continue;
        while (value > index)
        {
            if (index + 2 > vecInputArray.size())
            {
                index--;
                nShiftReq++;
                continue;
            }
            nShiftReq++;
            index = index + 2;
        }
        if (value < index)
        {
            nShiftReq += (index - value);
        }
    }
    if (nShiftReq % 3 == 0)
        return true;
    else
        return false;
}

int GeekSolver::calculate_3d_surface_area(int nWidth, int nLength, int **dimension)
{
    int nSurfaceArea = 0;
    int **ppBoard = new int *[nWidth + 2];
    int nNullHeightCnt = 0;
    for (int nIdx = 0; nIdx <= nWidth + 1; nIdx++)
    {
        ppBoard[nIdx] = new int[nLength + 2];
        ppBoard[nIdx][0] = 0;
        ppBoard[nIdx][nLength + 1] = 0;
    }
    for (int nIdx = 1; nIdx <= nLength + 1; nIdx++)
    {
        ppBoard[0][nIdx] = 0;
        ppBoard[nWidth + 1][nIdx] = 0;
    }
    for (int nRow = 1; nRow <= nWidth; nRow++)
    {
        for (int nCol = 1; nCol <= nLength; nCol++)
        {
            if (dimension[nRow - 1][nCol - 1] == 0)
                nNullHeightCnt++;
            ppBoard[nRow][nCol] = dimension[nRow - 1][nCol - 1];
        }
    }
    for (int i = 0; i < nWidth + 2; ++i)
    {
        for (int j = 0; j < nLength + 2; ++j)
        {
        }
    }
    for (int nRow = 1; nRow <= nWidth; nRow++)
    {
        for (int nCol = 1; nCol <= nLength; nCol++)
        {
            if (ppBoard[nRow][nCol] > ppBoard[nRow][nCol - 1])
            {
                nSurfaceArea += (ppBoard[nRow][nCol] - ppBoard[nRow][nCol - 1]);
            }
            if (ppBoard[nRow][nCol] > ppBoard[nRow - 1][nCol])
            {
                nSurfaceArea += (ppBoard[nRow][nCol] - ppBoard[nRow - 1][nCol]);
            }
            if (ppBoard[nRow][nCol] > ppBoard[nRow][nCol + 1])
            {
                nSurfaceArea += (ppBoard[nRow][nCol] - ppBoard[nRow][nCol + 1]);
            }
            if (ppBoard[nRow][nCol] > ppBoard[nRow + 1][nCol])
            {
                nSurfaceArea += (ppBoard[nRow][nCol] - ppBoard[nRow + 1][nCol]);
            }
        }
    }
    nSurfaceArea += (nWidth * nLength * 2);
    nSurfaceArea -= nNullHeightCnt;
    return nSurfaceArea;
}

Node<int> *GeekSolver::bst_to_gst(Node<int> *p_root)
{
    Node<int> *p_node = p_root;
    generate_greater_sum(p_node, 0);
    return p_root;
}

std::vector<int> GeekSolver::avoid_flood_in_city(std::vector<int> rains)
{
    std::set<int> setDryDays;
    std::vector<int> result_out;
    std::map<int, int> mapRainyDays;
    result_out.resize(rains.size());
    for (int nIndex = 0; nIndex < rains.size(); nIndex++)
    {
        if (rains[nIndex] > 0)
        {
            std::map<int, int>::iterator it = mapRainyDays.find(rains[nIndex]);
            if (mapRainyDays.end() == it)
            {
                mapRainyDays[rains[nIndex]] = nIndex;
                result_out[nIndex] = -1;
            }
            else
            {
                int nLastRainyday = mapRainyDays[rains[nIndex]];
                std::set<int>::iterator itSet = setDryDays.lower_bound(nLastRainyday + 1);
                if (itSet == setDryDays.end())
                    return {};
                else
                {
                    result_out[*itSet] = rains[nIndex];
                    setDryDays.erase(itSet);
                    mapRainyDays[rains[nIndex]] = nIndex;
                    result_out[nIndex] = -1;
                }
            }
        }
        else
        {
            setDryDays.insert(nIndex);
            result_out[nIndex] = 1;
        }
    }
    return result_out;
}

List *GeekSolver::addTwoNumbers(List *l1, List *l2)
{
    List *pTraverse_1 = nullptr;
    List *pTraverse_2 = nullptr;
    /*write corner cases*/
    if (l1 == nullptr)
    {
        return l1;
    }
    if (l2 == nullptr)
    {
        return l2;
    }
    int nCarryOver = 0;
    int nAddedValue = 0;
    do
    {
        pTraverse_1 = pTraverse_1 == nullptr ? l1 : pTraverse_1->p_next_;
        pTraverse_2 = pTraverse_2 == nullptr ? l2 : pTraverse_2->p_next_;

        nAddedValue = pTraverse_1->n_value_ + pTraverse_2->n_value_ + nCarryOver;
        pTraverse_1->n_value_ = nAddedValue % 10;
        nCarryOver = nAddedValue / 10;

    } while (pTraverse_1->p_next_ != nullptr && pTraverse_2->p_next_ != nullptr);

    if (pTraverse_1->p_next_ == nullptr && pTraverse_2->p_next_ == nullptr)
    {
        if (nCarryOver > 0)
        {
            List *pNode = new List(nCarryOver);
            pNode->p_next_ = nullptr;
            pTraverse_1->p_next_ = pNode;
        }
        return l1;
    }
    if (pTraverse_1->p_next_ == nullptr)
    {
        pTraverse_1->p_next_ = pTraverse_2->p_next_;
    }

    do
    {
        pTraverse_1 = pTraverse_1->p_next_;
        nAddedValue = pTraverse_1->n_value_ + nCarryOver;
        pTraverse_1->n_value_ = nAddedValue % 10;
        nCarryOver = nAddedValue / 10;
    } while (nCarryOver > 0 && pTraverse_1->p_next_ != nullptr);

    if (nCarryOver > 0)
    {
        List *pNode = new List(nCarryOver);
        pNode->p_next_ = nullptr;
        pTraverse_1->p_next_ = pNode;
    }
    return l1;
}
