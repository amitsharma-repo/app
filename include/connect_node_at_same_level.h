#include <iostream>
#include <binary_tree_utils.h>

template<typename T>
struct Node_with_nxt_right{
    Node<T>* p_node_;
Node<T>* p_next_right_;    
    Node<T>* get_left() { return p_node_->p_left; }
    Node<T>* get_right() { return p_node_->p_right; }
    Node_with_nxt_right( Node<T>* p_node ): p_node_(p_node) {}
    Node_with_nxt_right(int n_data):p_node_(new Node( n_data )), p_next_right_( nullptr ) 
    {}
};

template<typename T>
Node_with_nxt_right<T>* connect_node_at_same_level( Node_with_nxt_right<T>* p_node );

