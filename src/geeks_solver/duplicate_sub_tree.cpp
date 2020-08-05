#include<duplicate_sub_tree.h>

bool check_duplicate_sub_tree( Node<char>* p_root )
{
    std::set<std::string> set_sub_tree_matcher;
    // aply dfs on binary_tree
    return dfs( p_root, set_sub_tree_matcher );     
}

bool dfs( Node<char>* p_node, std::set<std::string>& set_sub_tree_matcher)
{
    if( p_node == nullptr )
        return false;
    if( p_node->p_left != nullptr && p_node->p_right != nullptr ) {
        std::string str_sub_tree;
        str_sub_tree.push_back( p_node->p_left->n_info);
        str_sub_tree.push_back( p_node->n_info ); 
        str_sub_tree.push_back( p_node->p_left->n_info );
        if( set_sub_tree_matcher.find( str_sub_tree ) != set_sub_tree_matcher.end() ) {
            std::cout << "matching string is " << str_sub_tree << std::endl;
            return true;
        } else {
            set_sub_tree_matcher.insert( str_sub_tree );
        }
    }
    return dfs( p_node->p_left, set_sub_tree_matcher ) || dfs( p_node->p_right, set_sub_tree_matcher ); 
}
