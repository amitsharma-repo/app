//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
#include<vector>
class NodeNxt {
public:
    int val;
    NodeNxt* left;
    NodeNxt* right;
    NodeNxt* next;

    NodeNxt() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    NodeNxt(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    NodeNxt(int _val, NodeNxt* _left, NodeNxt* _right, NodeNxt* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void create_tree_ptr(const std::vector<int>& vec_data, NodeNxt*& pRoot);
NodeNxt* connectNxt(NodeNxt* root);
