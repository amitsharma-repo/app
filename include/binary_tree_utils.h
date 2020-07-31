#pragma once
#include<vector>
#include <algorithm>
//template<typename T, typename Comp = std::less>
template< typename T, typename comp= std::less< void > >
struct  Node                                                                    
{                                                                               
    Node* p_right;                                                              
    Node* p_left;                                                               
    T     n_info;                                                                 
    Node(T n_data ): n_info( n_data ), p_right( nullptr ), p_left( nullptr )
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
template<typename T>
void add_node(Node<T>* pNode, T n_data);                                          

template<typename T>
Node<T>* create_binary_tree( std::vector<T> tree_data);                           

template<typename T>
int get_height( Node<T>* pNode );

template<typename T>
void print_level( Node<T>* p_node, int n_level, int n_spacer, int n_current_level = -1 );

template<typename T>
Node<T>* Display_tree( Node<T>* pNode );                                               

template<typename T>
void prettyPrintTree(Node<T>* node, std::string prefix = "", bool isLeft = true); 


#include<binary_tree_utils.inl>
