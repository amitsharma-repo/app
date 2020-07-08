#include <delete_node_with_greater_on_right.h>
 #include<util_struct.h> 

List* reverse( List* p_root )
{
    if( p_root == nullptr )
        return nullptr;
    if( p_root->p_next_ == nullptr )
        return p_root;
    List* p_prev_node = p_root;
    List* p_temp_node = p_root->p_next_;
    while( p_temp_node != nullptr )
    {
        List* nxt_ptr = p_temp_node->p_next_;
        p_temp_node->p_next_ = p_prev_node;
        p_prev_node = p_temp_node;
        p_temp_node = nxt_ptr; 
    }
    p_root->p_next_ = nullptr;
    return p_prev_node;
}
List* delete_node_with_greater_on_right(List* p_List)
{
    //reversing link List
    List* p_reverse_list = reverse( p_List );
    List* p_temp_node = p_reverse_list;
    int n_max = p_temp_node->n_value_;
    while( p_temp_node->p_next_ != nullptr )
    {
        if( p_temp_node->p_next_->n_value_ > n_max ) {
            n_max = p_temp_node->p_next_->n_value_;
            p_temp_node = p_temp_node->p_next_;
        }
        else {
            List* p_node = p_temp_node->p_next_;
            p_temp_node->p_next_ = p_temp_node->p_next_->p_next_;
            delete p_node;
        }
    }
    p_reverse_list = reverse( p_reverse_list );
    return p_reverse_list;
}
