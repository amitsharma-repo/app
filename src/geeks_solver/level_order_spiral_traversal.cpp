#pragma once
#include<math.h>
#include <level_order_spiral_traversal.h>
#include <queue>
std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

void add_node(Node* pNode, int n_data)                             
{                                                                               
    Node* p_parent;                                                             
    Node* p_temp_node = pNode;                                                  
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
                                                                                
Node* create_binary_tree( std::vector<int> tree_data)                           
{                                                                               
    Node* pRoot = new Node(tree_data[0]);                                                      
    std::for_each(tree_data.begin()+1, tree_data.end(), [&pRoot](int n_data){          
        add_node( pRoot, n_data );                                              
        } );                                                                       
    return pRoot;                                                               
}                                                                               

int get_height( Node* pNode )                                                       
{                                                                               
    int nHeight;                                                                
    if( pNode == nullptr )                                                      
        return 0;                                                               
    int n_left_height = get_height( pNode->p_left );                                
    int n_right_height = get_height( pNode->p_right );                              
    nHeight = n_left_height > n_right_height ? n_left_height +1 : n_right_height + 1;
    return nHeight ;                                                             
}                                                                                

void print_level( Node* p_node, int n_level, int n_spacer, int n_current_level )
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
    Node* p_left,*p_right;
    p_left = (p_node == nullptr) ? nullptr : p_node->p_left;
    p_right = (p_node == nullptr) ? nullptr : p_node->p_right;

    print_level( p_left, n_level, n_spacer, n_current_level -1 );
    print_level( p_right, n_level, n_spacer, n_current_level -1 );
}
Node* Display_tree( Node* pNode )                                               
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

void at_each_level( Node* pNode, int n_level, std::string& str_result, bool b_orient )
{
    if( pNode == nullptr )
        return ;
    //left orientation
    if( b_orient ) {
        if( n_level == 0 ) {
            str_result.append( std::to_string( pNode->n_info ));
            str_result.append(" ");
            return;
        } 
        at_each_level( pNode->p_left, n_level -1, str_result, b_orient );
        at_each_level( pNode->p_right, n_level -1, str_result, b_orient ); 
    }
    else { //right orientation
         if( n_level == 0 ) {                                                    
             str_result.append( std::to_string( pNode->n_info ));
             str_result.append(" ");
             return;                                                             
         }             
         at_each_level( pNode->p_right, n_level -1, str_result, b_orient );        
         at_each_level( pNode->p_left, n_level -1, str_result, b_orient ); 
    }
}

void level_order_spiral_traversal( Node* pNode, std::string& result )
{
    int nHeight = get_height( pNode );
    bool b_orient = false;
    for(int n_level =0 ; n_level < nHeight; ++n_level)  {
        at_each_level( pNode, n_level, result, b_orient );
        b_orient = !b_orient;
    }
   result = trim(result); 
}
