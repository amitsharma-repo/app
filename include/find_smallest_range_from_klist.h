#include<iostream> 
#include<vector> 
struct list
{
    int nValue;
    list* pNxt; 
};
std::tuple<int,int> find_smallest_range( int nList_cnt, list** pplist_collection);
