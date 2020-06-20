#pragma once
#include<tuple>
#include<level_order_spiral_traversal.h>
#include<find_smallest_range_from_klist.h>
#include<find_first_in_rotated_sorted_arr.h>
#include<find_min_number_from_given_sequence.h>
#include<find_duplicate_in_n_time.h>
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


TEST( test_level_order_spiral_traversal, spiral_traversal )
{
    std::vector<int> vec_tree_data {3, 43, 53, 64, 66, 5, 6};

//    std::vector<int> vec_tree_data {3, 45,9,12,78,87,99, 43, 53, 64, 66, 5, 6};
    Node* pNode = create_binary_tree( vec_tree_data );
    Display_tree( pNode ); 
    prettyPrintTree( pNode );
    std::string spiral_traversal;
    level_order_spiral_traversal( pNode, spiral_traversal );
    BOOST_CHECK_EQUAL( spiral_traversal, std::string("3 53 43 64 6 5 66") ); 
}

TEST( test_find_first_min_positive, find_first )
{
    int arr[8] = {2, 3, 7, 6, 8, -1, -10, 15};
    int min_positive = find_min_number_from_given_sequence(8, arr);
    BOOST_CHECK_EQUAL( min_positive, 1 );
    int arr_2[8] = { 2, 3, -7, 6, 8, 1, -10, 15 };
    min_positive = find_min_number_from_given_sequence(8, arr_2);
    BOOST_CHECK_EQUAL( min_positive, 4 );
    int arr_3[5] = {1, 1, 0, -1, -2};
    min_positive = find_min_number_from_given_sequence( 5, arr_3 );
    BOOST_CHECK_EQUAL( min_positive, 2 );
}
TEST( test_duplicate_in_n_array, find_duplicate )
{
    int arr[] = {1, 2, 3, 1, 3, 6, 6};  
    std::vector<int> result_vec = find_duplicate_in_n_time(7, arr);
    std::vector<int> result = {1, 3, 6};
    BOOST_CHECK_EQUAL(result_vec.size(), result.size());
    auto iter = result.begin();
    auto iter_vec = result_vec.begin();
    while( iter != result.end() ) {
        BOOST_CHECK_EQUAL( *iter, *iter_vec );
        iter++; iter_vec++;
    }
    int arr_1[] =  {1, 2, 3, 4 ,3}; 
    result_vec = find_duplicate_in_n_time(5, arr_1);
    result = {3};
    BOOST_CHECK_EQUAL(result_vec.size(), result.size());
    iter = result.begin();
    iter_vec = result_vec.begin();
    while( iter != result.end() ) {
        BOOST_CHECK_EQUAL( *iter, *iter_vec );
        iter++; iter_vec++;
    }
}
