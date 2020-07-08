#include<algorithm>
#include<find_smallest_range_from_klist.h>
#include<util_struct.h> 
#include<algorithm>
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
        if(pplist_collection[idx]->n_value_  > n_max)
            n_max = pplist_collection[idx]->n_value_ ;
    }
    std::make_heap(current_Heap.begin(), current_Heap.end(), [](List* x, List* y){
        return x->n_value_ >  y->n_value_ ; } );
    //finding minimum element
    List* pMinList = current_Heap.front(); 
    while(1)
    {
        
        /*std::cout << " min element value " << pMinList->n_value_ <<std::endl;
        std::for_each(current_Heap.begin(), current_Heap.end(), [](List* pList){
                std::cout << "heap data is " << pList->n_value_<< std::endl;
                });
        */
        //removing min element
        std::pop_heap(current_Heap.begin(), current_Heap.end());
        current_Heap.pop_back();

        if(pMinList->p_next_ == nullptr)
            break;
        List* element = pMinList->p_next_;
        //adding element in heap
        current_Heap.push_back(element);
        //hippifying the heap with new element added at the back
        std::make_heap(current_Heap.begin(), current_Heap.end(), [](List* x, List* y){
               return x->n_value_ > y->n_value_; } );
 
        //updating new minimum element
        pMinList = current_Heap.front();
        //upating elment_value to new arr_number
        if(element->n_value_  > n_max) {
            n_max = element->n_value_ ;
        }
        //update min of the new heap
         if((n_max -pMinList->n_value_ )  < nDiff_result) {
            nDiff_result = n_max - pMinList->n_value_ ;
            nStartIdx = pMinList->n_value_ ;
            nEndIndex = n_max;
            //std::cout << "min_elemt is " << nStartIdx << " max element is "<< nEndIndex << " diffence is " << nDiff_result << std::endl;
         }
    }
        
    return {nStartIdx, nEndIndex};
}

//}
