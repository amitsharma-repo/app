#include<binary_search_to_greater_sum.h>
int generate_greater_sum( Node<int>* p_node, int n_max_value )
{
    if( p_node == nullptr )
        return n_max_value;
    int n_right_greater = generate_greater_sum( p_node->p_right ,n_max_value);
    int new_value = n_right_greater + p_node->n_info;
    p_node->n_info = new_value;
    int n_left_greater = generate_greater_sum( p_node->p_left , p_node->n_info);
    return n_left_greater;
}
Node<int>* bst_to_gst( Node<int>* p_root )
{
    Node<int>* p_node = p_root;
    generate_greater_sum( p_node, 0);           
    return p_root;
}
