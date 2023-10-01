#include<iostream>                                                              
#include<vector>                                                                
#include<algorithm>
using namespace std;
struct List                                                                     
{                                                                               
    int n_value_;                                                                
    List* p_next_;                                                                
    List(int n_value, List* p_next = nullptr): n_value_(n_value),p_next_(p_next)         
    {}                                                                          
};                                                                              
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void debug_print( const List* p_node );
List* create_link_list(const std::vector<int>& vec_data);

void debug_print(const TreeNode* pNode);
TreeNode* create_tree(const std::vector<int>& vec_data);
