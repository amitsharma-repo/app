#include<find_smallest_range_from_klist.h>
#include<iostream>
#include<TestMain.cpp>

TEST(test_1, sample)
{
	 int nShared_res = 0;
     EXPECT_EQ(6 , nShared_res);

}

list* create_link_list(const std::vector<int>& vec_data)
{
    list *pList , *pStart;
    pList = pStart = nullptr;

    for_each( vec_data.begin(), vec_data.end(), [ & ](int nData){
            if( pList == nullptr) {
                pList = new list( nData );
                pStart = pList;
            }
            else {
                pList->pNxt_ = new list( nData );
                pList = pList->pNxt_;
            }
            });
    return pStart;
}

TEST(test_smallest_rangle, smallest_range)
{
    list **ppList = new list*[4];
    ppList[0]   = create_link_list( {2, 6, 7, 23, 56} );
    ppList[1]   = create_link_list( {3, 9, 40, 46, 34} );
    ppList[2]   = create_link_list( {56, 234, 563, 665, 786} );
    ppList[3]   = create_link_list( {6, 8, 12, 34, 76} ); 
    
    std::tuple<int,int> range= find_smallest_range(4, ppList);
    EXPECT_EQ(get<0>(range), 3);
    EXPECT_EQ(get<1>(range), 5);
}

