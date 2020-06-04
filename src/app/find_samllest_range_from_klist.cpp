#include<algorithm>
#include <c++/7/bits/c++config.h>
#include <cstdio>
#include<vector>
#include<map>

#include<iostream>
struct list
{
    int nValue;
    list* pNxt;
};
//input list is zagged array of list
std::tuple<int,int> find_smallest_rangle( int nList_cnt, list** pplist_collection)
{
    std::vector<list*> current_Heap;
    std::map<list* , int>  value_arr_idx;
    unsigned int nStartIdx, nEndIndex;
    unsigned int n_max = 0;
    unsigned int nDiff_result = 0;

    for ( int idx = 0; idx < nList_cnt; ++idx)
    {
        current_Heap.push_back(pplist_collection[idx]);
        value_arr_idx[pplist_collection[idx]] = idx;
        if(pplist_collection[idx]->nValue  > n_max)
            n_max = pplist_collection[idx]->nValue ;
    }
    std::make_heap(current_Heap.begin(), current_Heap.end(), [](list* x, list* y){
        return x->nValue  < y->nValue ; } );
    while(1)
    {
        //find minimum from the heap
        std::pop_heap(current_Heap.begin(), current_Heap.end());
        list* pMinList = current_Heap.back();
        current_Heap.pop_back();
        auto iter = value_arr_idx.find(pMinList) ;
        if(pplist_collection[iter->second]->pNxt == nullptr)
            break;
        list* element = pplist_collection[iter->second]->pNxt;
        //adding element in heap
        current_Heap.push_back(element);
        //hippifying the heap with new element added at the back
        std::push_heap(current_Heap.begin(), current_Heap.end() );
        //updating new minimum element
        pMinList = current_Heap.front();
        //upating elment_value to new arr_number
        value_arr_idx.erase(iter->first);
        value_arr_idx[element] = iter->second ;
        if(element->nValue  > n_max) {
            n_max = element->nValue ;
        }
        //update min of the new heap
         if((n_max -pMinList->nValue )  < nDiff_result) {
            nDiff_result = n_max - pMinList->nValue ;
            nStartIdx = pMinList->nValue ;
            nEndIndex = n_max;
         }
    }
        
    return {nStartIdx, nEndIndex};
}
