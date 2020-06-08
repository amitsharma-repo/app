#include<iostream> 
#include<vector> 
struct List
{
    int nValue_;
    List* pNxt_; 
    List(int nValue, List* pNxt = nullptr): nValue_(nValue),pNxt_(pNxt)
    {}
};
std::tuple<int,int> find_smallest_range( int nList_cnt, List** pplist_collection);
