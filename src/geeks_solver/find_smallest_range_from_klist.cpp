#include<algorithm>
#include<find_smallest_range_from_klist.h>
#include<algorithm>
#include <c++/7/bits/c++config.h>
#include <cstdio>
#include<vector>
#include<map>

#include<iostream>
//namespace app
//{
//input List is zagged array of list
std::tuple<int,int> find_smallest_range( int nList_cnt, List** pplist_collection)
{
    std::vector<List*> current_Heap;
    unsigned int nStartIdx, nEndIndex;
    unsigned int n_max = 0;
    unsigned int nDiff_result = 10000;

    for ( int idx = 0; idx < nList_cnt; ++idx)
    {
        current_Heap.push_back(pplist_collection[idx]);
        if(pplist_collection[idx]->nValue_  > n_max)
            n_max = pplist_collection[idx]->nValue_ ;
    }
    std::make_heap(current_Heap.begin(), current_Heap.end(), [](List* x, List* y){
        return x->nValue_ >  y->nValue_ ; } );
    //finding minimum element
    List* pMinList = current_Heap.front(); 
    while(1)
    {
        
        std::cout << " min element value " << pMinList->nValue_ <<std::endl;
        std::for_each(current_Heap.begin(), current_Heap.end(), [](List* pList){
                std::cout << "heap data is " << pList->nValue_<< std::endl;
                });
        //removing min element
        std::pop_heap(current_Heap.begin(), current_Heap.end());
        current_Heap.pop_back();

        if(pMinList->pNxt_ == nullptr)
            break;
        List* element = pMinList->pNxt_;
        //adding element in heap
        current_Heap.push_back(element);
        //hippifying the heap with new element added at the back
        std::make_heap(current_Heap.begin(), current_Heap.end(), [](List* x, List* y){
               return x->nValue_ > y->nValue_; } );
 
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
            std::cout << "min_elemt is " << nStartIdx << " max element is "<< nEndIndex << " diffence is " << nDiff_result << std::endl;
         }
    }
        
    return {nStartIdx, nEndIndex};
}

//}
