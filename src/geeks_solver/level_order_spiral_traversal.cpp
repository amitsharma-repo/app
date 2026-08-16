#pragma once
#include <level_order_spiral_traversal.h>
#include <queue>


template<typename T>
void level_order_spiral_traversal( Node<T>* pNode, std::string& result )
{
    int nHeight = get_height( pNode );
    bool b_orient = false;
    for(int n_level =0 ; n_level < nHeight; ++n_level)  {
        at_each_level( pNode, n_level, result, b_orient );
        b_orient = !b_orient;
    }
   result = trim(result); 
}
