#include <iostream>
#include <binary_tree_utils.h>

struct Node_with_nxt_right{
    Node* p_node_;
    Node* p_next_right_;    
    Node* get_left() { return p_node_->p_left; }
    Node* get_right() { return p_node_->p_right; }
    Node_with_nxt_right( Node* p_node ): p_node_(p_node) {}
    Node_with_nxt_right(int n_data):p_node_(new Node( n_data )), p_next_right_( nullptr ) 
    {}
};
Node_with_nxt_right* connect_node_at_same_level( Node_with_nxt_right* p_node );

