#pragma once
#include <level_order_spiral_traversal.h>
#include <queue>
/*
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
*/
template< typename T>
void at_each_level( Node<T>* pNode, int n_level, std::string& str_result, bool b_orient )
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

