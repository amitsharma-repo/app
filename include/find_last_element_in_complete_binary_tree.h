//finding last element in completely binary tree
#include<binary_tree_utils.h>
#include<vector>

template<typename T>
void create_complete_binary_tree(const std::vector<T>& vec_input);

template<typename T>
int find_last_in_complete_binary_tree(Node<T>* p_root, int& n_level );

template<typename T>
Node<T>* add_next_node( Node<T>* p_node, T n_value );

template<typename T>
Node<T>* check_right_most_is_leaf( Node<T>* p_node, int n_level );
