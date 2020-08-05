#include<iostream>
#include<binary_tree_utils.h>
#include<set>
bool check_duplicate_sub_tree( Node<char>* p_root );
bool dfs( Node<char>* p_node, std::set<std::string>& set_sub_tree_matcher );
