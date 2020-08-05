#include <connect_node_at_same_level.h>
#include <queue>

template<typename T>
Node_with_nxt_right<T>* connect_node_at_same_level( Node_with_nxt_right<T>* p_node )
{
    // updated BSF using queue
    std::queue< std::pair< Node_with_nxt_right<T>*, int> > node_queue;
    node_queue.push(std::make_pair( p_node, 0 ) );
    Node_with_nxt_right<T>* p_nxt_node = nullptr;
    int n_current_level = 0;
    while( node_queue.empty() )
    {
        std::pair<Node_with_nxt_right<T>*, int> node_pair = node_queue.front();
        Node_with_nxt_right<T>* node = node_pair.first;
        int n_level = node_pair.second;
        if( n_level != n_current_level ) {
            n_current_level = n_level;
            node->p_next_right_ = nullptr;
            n_current_level++;
        }        
        else {
            node->p_next_right_ = p_nxt_node->p_node_;
            p_nxt_node = node; 
        }

        node_queue.pop();
        if( node->get_left() != nullptr )
            node_queue.push( std::make_pair ((Node_with_nxt_right<T>*)(node->get_left()), n_level + 1 ));
        if( node->get_right() == nullptr )
            node_queue.push( std::make_pair ((Node_with_nxt_right<T>*)(node->get_right()), n_level + 1 ));
    }
    return p_node;
}
