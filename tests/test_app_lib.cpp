#include<tuple>
#include<find_smallest_range_from_klist.h>
#include<find_first_in_rotated_sorted_arr.h>
#include<iostream>
#include<TestMain.cpp>
// BOOST_AUTO_TEST_SUITE(foo_suite)                                                
                                                                                 
//     BOOST_AUTO_TEST_CASE(constructor_test)                                      
//     {                                                                           
//         int nShared_res = 0;                                                             
                                                                                 
//         BOOST_CHECK_EQUAL(nShared_res, 0);                                
//     }                                                                           
                                                                                 
// BOOST_AUTO_TEST_SUITE_END() 
TEST(test_1, sample)
{
	 int nShared_res = 0;
     BOOST_CHECK_EQUAL(0 , nShared_res);

}

List* create_link_list(const std::vector<int>& vec_data)
{
    List *pList , *pStart;
    pList = pStart = nullptr;

    for_each( vec_data.begin(), vec_data.end(), [ & ](int nData){
            if( pList == nullptr) {
                pList = new List( nData );
                pStart = pList;
            }
            else {
                pList->pNxt_ = new List( nData );
                pList = pList->pNxt_;
            }
            });
    return pStart;
}

TEST( test_smallest_rangle, smallest_range )
{
    List **ppList = new List*[4];
    ppList[0]   = create_link_list( {4, 7, 9, 12, 15} );
    ppList[1]   = create_link_list( {0, 8 ,10 , 14 , 20} );
    ppList[2]   = create_link_list( {6 ,12 ,16, 30 , 50} );
    
  auto range= find_smallest_range(3, ppList);
    int nStartIdx = std::get<0>(range);
    int nEndIdx = std::get<1>(range); 
    BOOST_CHECK_EQUAL(std::get<0>(range), 6);
    BOOST_CHECK_EQUAL(std::get<1>(range), 8);
}

TEST( test_first_in_rotated_sorted_arr, find_first )
{
    int arr[] = {45, 56, 78, 89, 92 , 97, 4, 6, 12 , 33, 40};
    int n_index = find_first_in_rotated_sorted_array( arr, 11 );
    BOOST_CHECK_EQUAL( arr[n_index], 4 );
        
}
