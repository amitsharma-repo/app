#include<iostream> 
#include<vector> 
struct list
{
    int nValue_;
    list* pNxt_; 
    list(int nValue, list* pNxt = nullptr): nValue_(nValue),pNxt_(pNxt)
    {}
};
std::tuple<int,int> find_smallest_range( int nList_cnt, list** pplist_collection);
