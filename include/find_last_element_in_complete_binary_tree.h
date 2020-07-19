//finding last element in completely binary tree
#include<binary_tree_utils.h>
#include<vector>

void create_complete_binary_tree(const std::vector<int>& vec_input);
int find_last_in_complete_binary_tree(Node* p_root, int& n_level );
Node* add_next_node( Node* p_node, int n_value );
Node* check_right_most_is_leaf( Node* p_node, int n_level );
