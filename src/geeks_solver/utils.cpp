#include<util_struct.h>

void debug_print( const List* p_node )
{
    while( p_node != nullptr )
    {
        std::cout << "node value " << p_node->n_value_ << std::endl;
        p_node = p_node->p_next_;
    }
}     

List* create_link_list(const std::vector<int>& vec_data)                        
{                                                                               
    List *pList , *pStart;                                                      
    pList = pStart = nullptr;                                                   
                                                                                
    for_each( vec_data.begin(), vec_data.end(), [ & ](int nData){               
            if( pList == nullptr) {                                             
                pList = new List( nData );                                      
                pStart = pList;                                                 
            }                                                                   
            else {                                                              
                pList->p_next_ = new List( nData );                             
                pList = pList->p_next_;                                         
            }                                                                   
            });                                                                 
                                                                                
    return pStart;                                                              
}            
