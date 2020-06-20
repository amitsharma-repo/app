#pragma once
#include<vector>
#include <algorithm>
//template<typename T, typename Comp = std::less>
struct  Node                                                                    
{                                                                               
    Node* p_right;                                                              
    Node* p_left;                                                               
    int n_info;                                                                 
    Node(int n_data ): n_info( n_data ), p_right( nullptr ), p_left( nullptr )
    { }
};                                                                              

enum class Traversal_type
{
    INORDER,
    PREORDER,
    POSTORDER,
    LEVELORDER,
    DEFAULT
};

void add_node(Node* pNode, int n_data);                                          
Node* create_binary_tree( std::vector<int> tree_data);                           
int get_height( Node* pNode );
void print_level( Node* p_node, int n_level, int n_spacer, int n_current_level = -1 );
Node* Display_tree( Node* pNode );                                               
void prettyPrintTree(Node* node, std::string prefix = "", bool isLeft = true); 
