#include<find_last_element_in_complete_binary_tree.h>
#include<queue>

void create_complete_binary_tree(const std::vector<int>& vec_input)
{
    std::queue< Node* > level_queue;
    std::queue< Node* > nxt_level_queue;
    Node* p_root =  new Node( vec_input[0] ); 
    level_queue.push( p_root );
    Node* p_parent;
    bool b_left_orient = true;
    for( int i = 1; i < vec_input.size(); ++i ) {   
        if( b_left_orient == false ) {
            if( level_queue.empty() )
                level_queue = nxt_level_queue;
            p_parent = level_queue.front();
            level_queue.front();
        }
        Node* p_child_node = add_next_node( p_parent, vec_input[ i ] );
        nxt_level_queue.push( p_child_node );
        b_left_orient != b_left_orient;     
    }   
}

Node* add_next_node(Node* p_node, int n_value)
{
    Node* p_child = new Node( n_value );
    if( p_node->p_left == nullptr )
        p_node->p_left = p_child;
    else
        p_node->p_right = p_child; 
    return p_child;
}

int find_last_in_complete_binary_tree(Node* p_root, int& n_level)
{
    if( n_level == -1)
    {
        n_level = 0;
        Node* node = p_root;
        while( node->p_left != nullptr ) {
            n_level++;
            node = node->p_left;
        }
    }
    if( p_root->p_left == nullptr && p_root->p_right == nullptr )
        return p_root->n_info;
    Node* p_node = p_root;
    int n_temp_level = n_level - 1;
    if( check_right_most_is_leaf( p_node->p_left, n_level -1 ) == nullptr ){
        return find_last_in_complete_binary_tree( p_node->p_left, n_temp_level);
    }    
    else {
       return find_last_in_complete_binary_tree( p_node->p_right, n_temp_level); 
    }
}

Node* check_right_most_is_leaf( Node* p_node, int n_level )
{
    while( p_node->p_right != nullptr) {
        p_node = p_node->p_right;
        n_level--;
    }
    if( n_level ==0 )
        return p_node->p_right;
    else
        return nullptr;
}
