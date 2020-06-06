#include<find_smallest_range_from_klist.h>
#include<algorithm>
#include <c++/7/bits/c++config.h>
#include <cstdio>
#include<vector>
#include<map>

#include<iostream>
//namespace app
//{
//input list is zagged array of list
std::tuple<int,int> find_smallest_range( int nList_cnt, list** pplist_collection)
{
    std::vector<list*> current_Heap;
    unsigned int nStartIdx, nEndIndex;
    unsigned int n_max = 0;
    unsigned int nDiff_result = 0;

    for ( int idx = 0; idx < nList_cnt; ++idx)
    {
        current_Heap.push_back(pplist_collection[idx]);
        if(pplist_collection[idx]->nValue_  > n_max)
            n_max = pplist_collection[idx]->nValue_ ;
    }
    std::make_heap(current_Heap.begin(), current_Heap.end(), [](list* x, list* y){
        return x->nValue_  < y->nValue_ ; } );
    while(1)
    {
        //find minimum from the heap
        std::pop_heap(current_Heap.begin(), current_Heap.end());
        list* pMinList = current_Heap.back();
        current_Heap.pop_back();
        if(pMinList->pNxt_ == nullptr)
            break;
        list* element = pMinList->pNxt_;
        //adding element in heap
        current_Heap.push_back(element);
        //hippifying the heap with new element added at the back
        std::push_heap(current_Heap.begin(), current_Heap.end() );
        //updating new minimum element
        pMinList = current_Heap.front();
        //upating elment_value to new arr_number
        if(element->nValue_  > n_max) {
            n_max = element->nValue_ ;
        }
        //update min of the new heap
         if((n_max -pMinList->nValue_ )  < nDiff_result) {
            nDiff_result = n_max - pMinList->nValue_ ;
            nStartIdx = pMinList->nValue_ ;
            nEndIndex = n_max;
         }
    }
        
    return {nStartIdx, nEndIndex};
}

//}