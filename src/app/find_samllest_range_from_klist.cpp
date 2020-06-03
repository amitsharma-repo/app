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
auto find_smallest_rangle( int nList_cnt, list** pplist_collection)
{
    std::vector<list*> current_Heap;
    std::map<int, list*>  value_arr_idx;
    unsigned int nStartIdx, nEndIndex;
    unsigned int n_max = 0;
    unsigned int nDiff_result = 0;

    for ( int idx = 0; idx < nList_cnt; ++idx)
    {
        current_Heap.push_back(pplist_collection[idx]);
        value_arr_idx[pplist_collection[idx][0]] = idx;
        if(pplist_collection[idx][0] > n_max)
            n_max = pplist_collection[idx][0];
    }
    std::make_heap(current_Heap.begin(), current_Heap.end(), [](int* x, int* y){
        return *x < *y;)
    } );
    while(1)
    {
        //find minimum from the heap
        std::pop_heap(current_Heap.begin(), current_Heap.end());
        int min = current_Heap.back();
        current_Heap.pop_back();
        auto iter = value_arr_idx.find(min);
        if(pplist_collection[index]->pNxt == nullptr)
            break;
        int element = pplist_collection[index]->pNxt;
        //adding element in heap
        current_Heap.push_back(element);
        //hippifying the heap with new element added at the back
        std::push_heap(current_Heap.begin(), current_Heap.end() );
        //updating new minimum element
        min = current_Heap.front();
        //upating elment_value to new arr_number
        value_arr_idx.remove(iter);
        value_arr_idx[element] = index;
        if(element > n_max) {
            n_max = element;
        }
        //update min of the new heap
         if((nMax -min) < nDiff_result) {
            nDiff_result = nMax - min;
            nStartIdx = min;
            nEndIndex = nMax;
         }
    }
        
    return {nStartIdx, nEndIndex};
}
