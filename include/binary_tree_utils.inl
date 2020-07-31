#include <math.h>
#include <iostream>
#include <binary_tree_utils.h>
template<typename T>
void add_node(Node<T>* pNode, T n_data)
{
    Node<T>* p_parent;
    Node<T>* p_temp_node = pNode;
    int n_dir;
    if( pNode == nullptr ) //creating first node as root node
        pNode = new Node( n_data );
    while( p_temp_node != nullptr)
    {
        p_parent = p_temp_node;
        n_dir = rand() % 2;
        if( n_dir == 0 )
            p_temp_node = p_temp_node->p_left;
        else
            p_temp_node = p_temp_node->p_right;
    }
    if( n_dir == 0 )
        p_parent->p_left = new Node(n_data);
    else
        p_parent->p_right = new Node(n_data);
}
template<typename T>
void print_level( Node<T>* p_node, int n_level, int n_spacer, int n_current_level )
{
    if(n_current_level == -1)
        n_current_level = n_level;
    if(n_current_level == 0) {
        if(p_node != nullptr) {
            std::cout << p_node->n_info;
        }
        else {
            std::cout << " ";
        }
        while( n_spacer-- ) std::cout << " ";
        return;
    }
    Node<T>* p_left,*p_right;
    p_left = (p_node == nullptr) ? nullptr : p_node->p_left;
    p_right = (p_node == nullptr) ? nullptr : p_node->p_right;

    print_level( p_left, n_level, n_spacer, n_current_level -1 );
    print_level( p_right, n_level, n_spacer, n_current_level -1 );
}
template<typename T>
Node<T>* Display_tree( Node<T>* pNode )
{
    int nHeight = get_height( pNode );
    std::cout << std::endl;
    for(int nlevel = 0 ; nlevel < nHeight; ++nlevel) {
        int n_spacer = pow(2 ,nHeight - nlevel - 1) -1;
        while(n_spacer >  0 && n_spacer--) std::cout<< " ";
        n_spacer = 2*(nHeight - nlevel) -1;
        print_level( pNode, nlevel, n_spacer);
        std::cout << std::endl << std::endl;
    }
}

template<typename T>
 Node<T>* create_binary_tree( std::vector<T> tree_data)
 {
     Node<T>* pRoot = new Node(tree_data[0]);
     std::for_each(tree_data.begin()+1, tree_data.end(), [&pRoot](int n_data){
         add_node( pRoot, n_data );
         } );
     return pRoot;
 }
 
template<typename T>
 int get_height( Node<T>* pNode )
 {
     int nHeight;
     if( pNode == nullptr )
         return 0;
     int n_left_height = get_height( pNode->p_left );
     int n_right_height = get_height( pNode->p_right );
     nHeight = n_left_height > n_right_height ? n_left_height +1 : n_right_height + 1;
     return nHeight ;
 }

template<typename T>
 void prettyPrintTree(Node<T>* node, std::string prefix, bool isLeft) {
     if (node == nullptr) {
         std::cout << "Empty tree";
         return;
     }
 
     if(node->p_right) {
         prettyPrintTree(node->p_right, prefix + (isLeft ? "│   " : "    "), false);
     }
     std::cout << prefix + (isLeft ? "└── " : "┌── ") + std::to_string(node->n_info) + "\n";
 
     if (node->p_left) {
         prettyPrintTree(node->p_left, prefix + (isLeft ? "    " : "│   "), true);
     }
 } 
