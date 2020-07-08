#include<iostream>                                                              
#include<vector>                                                                
#include<algorithm>
using namespace std;
struct List                                                                     
{                                                                               
    int n_value_;                                                                
    List* p_next_;                                                                
    List(int n_value, List* p_next = nullptr): n_value_(n_value),p_next_(p_next)         
    {}                                                                          
};                                                                              
void debug_print( const List* p_node );
List* create_link_list(const std::vector<int>& vec_data);
