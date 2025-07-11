#pragma once
#include<tuple>
#include <fstream>
#include<iostream>

#include<TestMain.h>

#include<reverse_nodes_in_k_group.h>
//#include<remove_nth_node_from_end.h>
#include<image_rotate.h>
#include<count_and_say.h>
#include<search_in_rotated_array.h>
#include<avoid_flood_in_city.h>
#include<min_jump_to_reach_home.h>
#include<find_circular_loop.h>
#include<letter_combination_of_phone_number.h>
#include<generate_parantheses.h>
#include<check_larry_array.h>
#include<find_max_area_of_container.h>
#include<calculate_3d_surface_area.h>
#include<partition_array_into_disjoint_interval.h> 
#include<min_flip_for_monotone_increasing.h>
#include<binary_search_to_greater_sum.h>
#include<reverse_digit_integer.h>
#include<string_to_integer.h>
#include<duplicate_sub_tree.h>
#include<triplet_with_zero_sum.h>
#include<level_order_spiral_traversal.h>
#include<find_smallest_range_from_klist.h>
#include<find_first_in_rotated_sorted_arr.h>
#include<find_min_number_from_given_sequence.h>
#include<find_duplicate_in_n_time.h>
#include<delete_node_with_greater_on_right.h>
#include<longest_valid_parantheses.h>
#include<maximum_index.h>
#include<duplicate_sub_tree.h>
#include<jumping_number.h>
#include<partition_list.h>
#include<partition_smallerValue.h>
#include<add_two_number_list.h>
#include<rotate_list.h>
#include<reverse_link_list.h>
#include<reverse_link_list_between_position.h>
#include<sortedListToBST.h>
#include<flatten_binary_tree.h>
#include<next_rightptr_tree.h>
#include<LRU_Cache.h>
#include<split_linked_list.h>
#include<count_number_of_atoms.h>
#include<distinct_substring_of_size_n.h>
#include<longest_nice_substring.h>
#include<longest_substr_without_repeat.h>
#include<median_of_two_sorted_array.h>
#include<jump_game.h>
#include<isValidBST.h>
#include<merge_sort_array.h>
#include<restoreIPAddress.h>
#include<remove_dublicate.h>
#include<remove_element.h>
#include<remove_dublicate_sorted.h>
#include<majority_element.h>
#include<rotatate_array.h>
#include<max_profit_once.h>
#include<max_profit.h>
//#include<util_struct.h>
#include <vector>



// BOOST_AUTO_TEST_SUITE(foo_suite)                                                
                                                                                 
//     BOOST_AUTO_TEST_CASE(constructor_test)                                      
//     {                                                                           
//         int nShared_res = 0;                                                             
                                                                                 
//         BOOST_CHECK_EQUAL(nShared_res, 0);                                
//     }                                                                           
                                                                                 
// BOOST_AUTO_TEST_SUITE_END() 

bool test_link_list( const List* p_result, const std::vector<int>&& vec_result)
{
    bool b_result = true;;
    auto iter = vec_result.begin();
    while( b_result && iter != vec_result.end() )
    {
        if( p_result == nullptr) {
            b_result = false;
            break;
        }
        if( *iter != p_result->n_value_ )
            b_result = false;
        BOOST_CHECK_EQUAL( *iter, p_result->n_value_);
        p_result = p_result->p_next_; 
        iter++; 
    }
    return b_result;
}

TEST( test_geeks_solver, sample)
{
	 int nShared_res = 0;
     BOOST_CHECK_EQUAL(0 , nShared_res);
}

TEST( test_geeks_solver, smallest_range )
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

TEST( test_geeks_solver, find_first )
{
    int arr[] = {45, 56, 78, 89, 92 , 97, 4, 6, 12 , 33, 40};
    int n_index = find_first_in_rotated_sorted_array( arr, 11 );
    BOOST_CHECK_EQUAL( arr[n_index], 4 );
        
}

TEST( test_geeks_solver, spiral_traversal )
{
    std::vector<int> vec_tree_data {3, 43, 53, 64, 66, 5, 6};

//    std::vector<int> vec_tree_data {3, 45,9,12,78,87,99, 43, 53, 64, 66, 5, 6};
    Node<int>* pNode = create_binary_tree( vec_tree_data );
    //Display_tree( pNode ); 
    //prettyPrintTree( pNode );
    std::string spiral_traversal;
    level_order_spiral_traversal( pNode, spiral_traversal );
    BOOST_CHECK_EQUAL( spiral_traversal, std::string("3 64 43 53 6 66 5") ); 
}

/*TEST( test_geeks_solver, find_min_positive)
{
    int arr[8] = {2, 3, 7, 6, 8, -1, -10, 15};
    int min_positive = find_min_number_from_given_sequence(8, arr);
    //BOOST_CHECK_EQUAL( min_positive, 1 );
    int arr_2[8] = { 2, 3, -7, 6, 8, 1, -10, 15 };
    min_positive = find_min_number_from_given_sequence(8, arr_2);
    //BOOST_CHECK_EQUAL( min_positive, 4 );
    int arr_3[5] = {1, 1, 0, -1, -2};
    min_positive = find_min_number_from_given_sequence( 5, arr_3 );
    std::cout << min_positive << std::endl;
        
    //BOOST_CHECK( min_positive == 2 );
}*/

TEST( test_geeks_solver, find_duplicate )
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

TEST( test_geeks_solver, delete_greater)
{
    std::vector<int> input_vec = {15, 10, 11, 5, 6, 2, 3};
    List* p_start = create_link_list( input_vec );
    List* p_result_list = delete_node_with_greater_on_right( p_start );
    test_link_list( p_result_list, {15, 11, 6 ,3} );

    input_vec = { 10, 20 ,30 ,40, 50 , 60 };
    p_start =  create_link_list( input_vec );
    p_result_list  = delete_node_with_greater_on_right( p_start );
    test_link_list( p_result_list, { 60 } );
}
TEST( test_geeks_solver, maximum_index )
{
    std::vector<int> vec_input = {34, 8, 10, 3, 2, 80,30, 33, 1}; 
    int n_reuslt = find_max_index( vec_input ); 
    BOOST_CHECK_EQUAL( 6, n_reuslt );
}
TEST( test_geeks_solver, longest_valid_parantheses )
{
    std::string input_string = "()(((()))()()((())))(((()()())()";
    int n_result = find_longest_valid_parantheses( input_string );
    BOOST_CHECK_EQUAL( n_result, 18 );
}
TEST( test_geeks_solver, jumping_number_list )
{
    std::vector<int> vec_result = find_jumping_number_list( 450 );
    BOOST_CHECK_EQUAL( vec_result.size(), 40);    
/*
    std::for_each( vec_result.begin(), vec_result.end(), []( int n){
            std::cout << n << std::endl;
            } );
*/
}
TEST( test_geeks_solver, triplet_with_zero_sum )
{
    BOOST_CHECK_EQUAL( find_triptet_with_zero_sum( { 0, -1, 2, -3, 1 } ), true );
    BOOST_CHECK_EQUAL( find_triptet_with_zero_sum( { 1, -2, 1, 0, 5 } ), true);
    BOOST_CHECK_EQUAL( find_triptet_with_zero_sum( { 1, 2, 1, 0, 5 } ), false);

}

TEST( test_geeks_solver, test_dublicate_sub_tree )
{
    std::vector<char> input_vec_data = {'d', 'y', 'h', 'd', 'y', 'h', 'd', 'y', 'h', 'd', 'y', 'h', 'd', 'y', 'h', 'd', 'y', 'h', 'd', 'y', 'h', 'd', 'y', 'h'};
    Node<char>* p_root_node = create_binary_tree( input_vec_data );
    //Display_tree( p_root_node );
    //prettyPrintTree( p_root_node ); 
    BOOST_CHECK_EQUAL( check_duplicate_sub_tree( p_root_node ), true ); 
}
TEST( test_geeks_solver, test_sring_to_integer )
{
    BOOST_CHECK_EQUAL( my_atoi( "3454"), 3454 );
    BOOST_CHECK_EQUAL( my_atoi( "-34" ), -34 );
    BOOST_CHECK_EQUAL( my_atoi( "34sd" ), 34 );
    BOOST_CHECK_EQUAL( my_atoi( "    -43" ), -43);
    BOOST_CHECK_EQUAL( my_atoi( "    43" ), 43);
    BOOST_CHECK_EQUAL( my_atoi( "    43 with word" ), 43);
    BOOST_CHECK_EQUAL( my_atoi( "-91283472332" ), -2147483648 );
}
TEST( test_geeks_solver, test_reverse_digit_integer )
{
    BOOST_CHECK_EQUAL( get_reverse_digit_of_integer( -1234 ), -4321 );
    BOOST_CHECK_EQUAL( get_reverse_digit_of_integer( 4532 ), 2354 );
    BOOST_CHECK_EQUAL( get_reverse_digit_of_integer( 1534236469 ), 0 );
}
TEST( test_geeks_solver, test_bst_to_gst )
{
    std::vector<int> input_vec_data = {1 ,7, 8, 4, 3, 7, 2, 67, 33, 13, 5};
    Node<int>* p_root_node = create_binary_tree( input_vec_data );
    prettyPrintTree( p_root_node ); 
    bst_to_gst( p_root_node );
    prettyPrintTree( p_root_node );
}
TEST( test_geeks_solver, test_min_flip_monotone_increasing )
{
    std::string input_string = "00110";
    int n_min_result = min_flip_monotone_increasing( input_string );
    BOOST_CHECK_EQUAL( n_min_result, 1 );
    input_string = "010110";
    n_min_result = min_flip_monotone_increasing( input_string );
    BOOST_CHECK_EQUAL( n_min_result, 2 );
    input_string = "00011000";
    n_min_result = min_flip_monotone_increasing( input_string );
    BOOST_CHECK_EQUAL( n_min_result, 2 );
}
TEST( test_geeks_solver, test_partition_into_disjoint_interval )
{
    std::vector<int> input_data = { 5,0,3,8,6 };
    int n_partition_index = find_partition_array_into_disjoint_interval( input_data );
    BOOST_CHECK_EQUAL( n_partition_index, 3 );
    input_data = { 1,1,1,0,6,12 };
    n_partition_index = find_partition_array_into_disjoint_interval( input_data );
    BOOST_CHECK_EQUAL( n_partition_index, 4 );    
}

TEST(test_geeks_solver, test_calculate_3d_surface_area )
{
    int inputDimension[3][3] = {
                                {1,3,4},
                                {2,2,3},
                                {1,2,4}                                    
                               };
    int *surrogate[3];
    for (size_t i = 0; i < 3; ++i)
    {
        surrogate[i] = inputDimension[i];
    }
    int nSurfaceArea = calculate_3d_surface_area(3 ,3 ,surrogate);
    BOOST_CHECK_EQUAL( nSurfaceArea, 60 );
}
TEST(test_geeks_solver, test_check_larry_array )
{
    bool result;
    /*
    std::vector<int> vec_input_1 = {1, 6, 5, 2, 4, 3};
    result = check_larry_array(vec_input_1 );
    BOOST_CHECK_EQUAL( result, true);
    std::vector<int> vec_input_2 = {3, 1, 2};
    result =check_larry_array(vec_input_2);
    BOOST_CHECK_EQUAL( result, true);
    std::vector<int> vec_input_3= {1, 3, 4, 2};
    result = check_larry_array(vec_input_3);
    BOOST_CHECK_EQUAL( result, true);
    */
    std::vector<int> vec_input_4= {1, 2, 3, 5, 4};
    result = check_larry_array(vec_input_4);
   // BOOST_CHECK_EQUAL( result, false);
}
TEST(test_geeks_solver, test_find_max_area_of_container )
{
    std::vector heights = {1,8,6,2,5,4,8,3,7};
    int nMaxWater = find_max_area(heights);
    BOOST_CHECK_EQUAL( nMaxWater, 49);

}
TEST(test_geeks_solver, test_letter_combination_of_phone_number )
{
    std::string strDigit = "23";
    std::vector<std::string> vec_result = letter_combination_of_phone_number(strDigit);
    std::vector<std::string> vec_check_result= {"ad","ae","af","bd","be","bf","cd","ce","cf"};
    auto iter = vec_result.begin();
    auto iter_check = vec_check_result.begin();
    BOOST_CHECK_EQUAL( vec_check_result.size(), vec_result.size());
    while( iter!= vec_result.end() ) {
        BOOST_CHECK_EQUAL( *iter, *iter_check );
        ++iter; ++iter_check;
    }
}
TEST( test_geeks_solver, test_generate_parenthesis )
{
    std::vector<std::string> resultParantheses;
    //resultParantheses = generateParenthesis(4);
/*    std::vector<std::string> vec_result_parantheses = {"()()()", "(())()", "(()())", "()(())" ,"((()))"}; 
    for(auto str: vec_result_parantheses)
        std::cout << str << " ";
    std::cout << "output is " << std::endl;
    for(auto str: resultParantheses)
        std::cout << str << " ";
    vector<std::string>::iterator it= std::unique( resultParantheses.begin(), resultParantheses.end() );
    bool wasUnique = (it == resultParantheses.end() );
    std::cout << "was unique " << wasUnique << std::endl;
    BOOST_CHECK_EQUAL( resultParantheses.size(), vec_result_parantheses.size());
    auto iter = resultParantheses.begin();
    auto iter_result = vec_result_parantheses.begin();
    while( iter != resultParantheses.end() )
    {
        BOOST_CHECK_EQUAL( *iter, *iter_result );
        ++iter, ++iter_result;
    }
    resultParantheses = generateParenthesis(1);
    vec_result_parantheses = { "()" }; 
    for(auto str: resultParantheses)
        std::cout << str << std::endl;
    BOOST_CHECK_EQUAL( resultParantheses.size(), vec_result_parantheses.size());
    iter = resultParantheses.begin();
    iter_result = vec_result_parantheses.begin();
    std::sort(vec_result_parantheses.begin(), vec_result_parantheses.end());
    std::sort(resultParantheses.begin(), resultParantheses.end());
    while( iter != resultParantheses.end() )
    {
        BOOST_CHECK_EQUAL( *iter, *iter_result );
        ++iter, ++iter_result;
    }
    */
}
TEST( test_geeks_solver, test_circular_loop )
{
    bool isCircularLoop;
    std::vector<int> vec_input = {-1,-1,-1};
    isCircularLoop = check_circular_loop(vec_input);
    BOOST_CHECK_EQUAL( isCircularLoop, true);
    vec_input = {-2,1,-1,-2,-2};
    isCircularLoop = check_circular_loop(vec_input);
    BOOST_CHECK_EQUAL( isCircularLoop, false);
    vec_input = {-1,2};
    isCircularLoop = check_circular_loop(vec_input);
    BOOST_CHECK_EQUAL( isCircularLoop, false);
    vec_input = {2,-1,1,2,2};
    isCircularLoop = check_circular_loop(vec_input);
    BOOST_CHECK_EQUAL( isCircularLoop, true);
    vec_input = {2,2,2,2,2,4,7};
    isCircularLoop = check_circular_loop(vec_input);
    BOOST_CHECK_EQUAL( isCircularLoop, false);
}

TEST( test_geeks_solver, test_avoid_flood_in_city )
{
    std::vector<int> vec_input = {1,2,3,4};
    std::vector<int> result_vec;
    std::vector<int> expected_output = {-1,-1,-1,-1};
    std::vector<int>::iterator iter_expected = expected_output.begin();
    result_vec = avoid_flood_in_city(vec_input);
    std::vector<int>::iterator iter_result = result_vec.begin();
    
    BOOST_CHECK_EQUAL( expected_output.size(), result_vec.size());
    while(iter_result != result_vec.end())    
    {
        BOOST_CHECK_EQUAL(*iter_result, *iter_expected);
        iter_result++; iter_expected++;
    }
    //next test case/
    vec_input = {1,2,0,0,2,1};
    expected_output = {-1,-1,2,1,-1,-1};
    result_vec = avoid_flood_in_city(vec_input);
    iter_result = result_vec.begin();
    iter_expected = expected_output.begin();
    BOOST_CHECK_EQUAL( expected_output.size(), result_vec.size());
    while(iter_result != result_vec.end())    
    {
        BOOST_CHECK_EQUAL(*iter_result, *iter_expected);
        iter_result++; iter_expected++;
    }
    //next test case/
    vec_input = {1,2,0,1,2};
    expected_output = {};
    result_vec = avoid_flood_in_city(vec_input);
    iter_result = result_vec.begin();
    iter_expected = expected_output.begin();
    BOOST_CHECK_EQUAL( expected_output.size(), result_vec.size());
    while(iter_result != result_vec.end())    
    {
        BOOST_CHECK_EQUAL(*iter_result, *iter_expected);
        iter_result++; iter_expected++;
    }
    //next test case
    vec_input = {69,0,0,0,69};
    expected_output = {-1,69,1,1,-1};
    result_vec = avoid_flood_in_city(vec_input);
    iter_result = result_vec.begin();
    iter_expected = expected_output.begin();
    BOOST_CHECK_EQUAL( expected_output.size(), result_vec.size());
    while(iter_result != result_vec.end())    
    {
        BOOST_CHECK_EQUAL(*iter_result, *iter_expected);
        iter_result++; iter_expected++;
    }
     // next test case/
    vec_input = {0,1,1};
    expected_output = {};
    result_vec = avoid_flood_in_city(vec_input);
    iter_result = result_vec.begin();
    iter_expected = expected_output.begin();
    BOOST_CHECK_EQUAL( expected_output.size(), result_vec.size());
    while(iter_result != result_vec.end())    
    {
        BOOST_CHECK_EQUAL(*iter_result, *iter_expected);
        iter_result++; iter_expected++;
    }
    //next test case/
    vec_input = {1,0,2,0,2,1};
    expected_output = {-1,1,-1,2,-1,-1};
    result_vec = avoid_flood_in_city(vec_input);
    iter_result = result_vec.begin();
    iter_expected = expected_output.begin();
    BOOST_CHECK_EQUAL( expected_output.size(), result_vec.size());
    while(iter_result != result_vec.end())    
    {
        BOOST_CHECK_EQUAL(*iter_result, *iter_expected);
        iter_result++; iter_expected++;
    }
    //next test case
    vec_input = {1,0,2,0,3,0,2,0,0,0,1,2,3};
    expected_output = {-1,1,-1,2,-1,3,-1,2,1,1,-1,-1,-1};
    result_vec = avoid_flood_in_city(vec_input);
    iter_result = result_vec.begin();
    iter_expected = expected_output.begin();
    BOOST_CHECK_EQUAL( expected_output.size(), result_vec.size());
    while(iter_result != result_vec.end())    
    {
        BOOST_CHECK_EQUAL(*iter_result, *iter_expected);
        iter_result++; iter_expected++;
    }
}

TEST( test_geeks_solver, test_minimum_jump_to_reach_home)
{
    std::vector<int> vec_forbidden;
    int n_jump_result;
    /*vec_forbidden = {14,4,18,1,15};
    n_jump_result = minimumJumps(vec_forbidden, 3, 15, 9);
    BOOST_CHECK_EQUAL( n_jump_result, 3);
    */
    vec_forbidden = {1,6,2,14,5,17,4};
    n_jump_result = minimumJumps(vec_forbidden, 16, 9, 7);
    BOOST_CHECK_EQUAL( n_jump_result, 2);
}
/*
TEST( test_geeks_solver, test_remove_nth_node_from_last)
{
    List* pInputList;
    List* pOutputList;
    List* pResultList;
    pInputList = create_link_list( {4, 7, 9, 12, 15} );
    pOutputList = create_link_list( {4, 7, 9, 15} );
    pResultList = removeNthFromEnd( pInputList, 2 );
    while( pOutputList == nullptr) {
        BOOST_CHECK_EQUAL( pOutputList->n_value_, pResultList->n_value_);
        pOutputList = pOutputList->p_next_;
        pResultList = pResultList->p_next_;
    }
}
*/
TEST( test_geeks_solver, reverse_nodes_in_k_group )
{
    List* pInputList;
    List* pOutputList;
    List* pResultList;
    pInputList = create_link_list( {1,2,3,4,5} );
    pOutputList = create_link_list( {3,2,1,4,5} );
    pResultList = reverseKGroup(pInputList, 3);
    while( pOutputList != nullptr) {
        BOOST_CHECK_EQUAL( pOutputList->n_value_, pResultList->n_value_);
        pOutputList = pOutputList->p_next_;
        pResultList = pResultList->p_next_;
    }
    pInputList = create_link_list( {1} );
    pOutputList = create_link_list( {1} );
    pResultList = reverseKGroup(pInputList, 1);
    while( pOutputList != nullptr) {
        BOOST_CHECK_EQUAL( pOutputList->n_value_, pResultList->n_value_);
        pOutputList = pOutputList->p_next_;
        pResultList = pResultList->p_next_;
    }
    pInputList = create_link_list( {1,2} );
    pOutputList = create_link_list( {2,1} );
    pResultList = reverseKGroup(pInputList, 2);
    while( pOutputList != nullptr) {
        BOOST_CHECK_EQUAL( pOutputList->n_value_, pResultList->n_value_);
        pOutputList = pOutputList->p_next_;
        pResultList = pResultList->p_next_;
    }
    pInputList = create_link_list( {1,2,3,4} );
    pOutputList = create_link_list( {2,1,4,3} );
    pResultList = reverseKGroup(pInputList, 2);
    while( pOutputList != nullptr) {
        BOOST_CHECK_EQUAL( pOutputList->n_value_, pResultList->n_value_);
        pOutputList = pOutputList->p_next_;
        pResultList = pResultList->p_next_;
    }
}
TEST( test_geeks_solver, search_in_rotated_array )
{
    std::vector<int> input_arr;
    int nResult;
    input_arr = {4,5,6,7,0,1,2};
    nResult = search(input_arr, 0);
    BOOST_CHECK_EQUAL( nResult, 4);

}
TEST( test_geeks_solver, cout_and_say )
{
    std::string res_count_and_say;
    res_count_and_say = countAndSay(1);        
    BOOST_CHECK_EQUAL( res_count_and_say, "1");
    res_count_and_say = countAndSay(2);        
    BOOST_CHECK_EQUAL( res_count_and_say, "11");
    res_count_and_say = countAndSay(3);        
    BOOST_CHECK_EQUAL( res_count_and_say, "21");
    res_count_and_say = countAndSay(4);        
    BOOST_CHECK_EQUAL( res_count_and_say, "1211");
    res_count_and_say = countAndSay(5);        
    BOOST_CHECK_EQUAL( res_count_and_say, "111221");
    res_count_and_say = countAndSay(6);        
    BOOST_CHECK_EQUAL( res_count_and_say, "312211");
}
TEST( test_geeks_solver, partition_list)
{
  List *pInputList = create_link_list( {1,4,3,2,5,2} );
  partition(pInputList, 3); 
}
TEST( test_geeks_solver, partitionSmaller)
{
  List *pInputList = create_link_list( {1,4,3,2,5,2} );
  List *pResultList= create_link_list( {1,2,2,4,3,5} );
  partition_smaller(pInputList, 3); 
  while( pInputList != nullptr) {
    BOOST_CHECK_EQUAL( pInputList->n_value_, pResultList->n_value_);
    pInputList= pInputList->p_next_;
    pResultList = pResultList->p_next_;
  }
  pInputList = create_link_list( {1,2,3} );
  pResultList= create_link_list( {1,2,3} );

  partition_smaller(pInputList, 4); 
  while( pInputList != nullptr) {
    BOOST_CHECK_EQUAL( pInputList->n_value_, pResultList->n_value_);
    pInputList= pInputList->p_next_;
    pResultList = pResultList->p_next_;
  }
}
TEST( test_geeks_solver, rotate_list)
{
  List *pInputList = create_link_list( {1,2,3,4,5} );
  List *pResultList= create_link_list( {4,5,1,2,3} );
  List* pNode = rotateList(pInputList, 2); 
  while( pNode != nullptr) {
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }
  pInputList = create_link_list( {1,2} );
  pResultList= create_link_list( {2,1} );

  pNode = rotateList(pInputList, 99); 
  while( pNode != nullptr) {
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }
}

TEST( test_geeks_solver, add_number_list)
{
  List *pInputList_1= create_link_list( {2,4,3} );
  List *pInputList_2= create_link_list( {5,6,4} );

  List *pResultList= create_link_list( {7,0,8} );

  List* pNode = addTwoNumbers(pInputList_1, pInputList_2); 
  while( pNode != nullptr) {
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }
  pInputList_1= create_link_list( {0} );
  pInputList_2= create_link_list( {0} );

  pResultList= create_link_list( {0} );

  pNode = addTwoNumbers(pInputList_1, pInputList_2); 

  while( pNode != nullptr) {
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }

  pInputList_1= create_link_list( {9,9,9,9,9,9,9} );
  pInputList_2= create_link_list( {9,9,9,9} );

  pResultList= create_link_list( {8,9,9,9,0,0,0,1} );

  pNode = addTwoNumbers(pInputList_1, pInputList_2); 
  while( pNode != nullptr) {
    
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }
}

TEST( test_geeks_solver, reverse_link_list)
{
  List *pInputList = create_link_list( {1,2,3,4,5} );
  List *pResultList= create_link_list( {1,4,3,2,5} );

  List* pNode = reverseBetween(pInputList, 2, 4); 
  while( pNode != nullptr) {
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }
}

TEST( test_geeks_solver, reverse_link_list_bw_position)
{
  List *pInputList = create_link_list( {1,2,3,4,5} );
  List *pResultList= create_link_list( {1,4,3,2,5} );

  List* pNode = reverseBetween_position(pInputList, 2, 4); 
  while( pNode != nullptr) {
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }
  pInputList = create_link_list( {3,5} );
  pResultList= create_link_list( {5,3} );

  pNode = reverseBetween_position(pInputList, 1, 2); 
  while( pNode != nullptr) {
    BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    pNode = pNode->p_next_;
    pResultList = pResultList->p_next_;
  }
}

TEST( test_geeks_solver, sortedListToBST)
{
  List *pInputList = create_link_list( {0,1,2,3,4,5} );
  TreeNode* pNode = sortedListToBST(pInputList); 
  //while( pNode != nullptr) {
    //BOOST_CHECK_EQUAL( pNode->n_value_, pResultList->n_value_);
    //pNode = pNode->p_next_;
    //pResultList = pResultList->p_next_;
  //}
}
TEST( test_geeks_solver, flattenBST)
{
  TreeNode *pInputList = create_tree( {1,2,5,3,4,-99,6} );
  TreeNode *pResultList = create_tree({1,-99,2,-99,3,-99,4,-99,5,-99,6});
  /*flatten(pInputList); 
  while( pInputList!= nullptr) {
    BOOST_CHECK_EQUAL( pInputList->val, pResultList->val);
    pInputList= pInputList->right;
    pResultList = pResultList->right;
  }
  */
}
TEST( test_geeks_solver, nxt_right_ptr)
{
  NodeNxt *pInputList = nullptr;
  create_tree_ptr( {1,2,3,4,5,-99,7} , pInputList);
  //NodeNxt *pResultList = create_tree_ptr({1,-99,2,-99,3,-99,4,-99,5,-99,6});
  connectNxt(pInputList); 
  /**
  while( pInputList!= nullptr) {
    BOOST_CHECK_EQUAL( pInputList->val, pResultList->val);
    pInputList= pInputList->right;
    pResultList = pResultList->right;
  }
  */
}
TEST( test_geeks_solver, lru_cache)
{
  std::vector<string> vecOperation = {"LRUCache","put","get","put","get","get","put","put","get","get","get","get","put","put","get","put","get","get","put","put","put","put","put","put","put","get","put","get","put","get","put","put","get","get","put","get","put","get","get","put","get","get","get","get","put","put","get","get","get","put","get","put","get","put","get","get","put","put","put","put","put","get","get","put","put","get","put","put","get","put","get","get","put","put","put","get","get","put","put","put","put","get","get","put","get","put","put","put","get","get","put","get","put","get","get","put","put","put","get","get","put","put","put","get","put","put","put","get","put","put","get","put","get","get","get","get","put","put","put","put","get","put","get","get","put","get","get","get","put","put","put","get","put","put","put","get","put","get","put","get","get","put","get","put","put","put","put","put","put","get","put","get","get","put","get","put","put","put","put","put","get","get","get","put","put","put","put","put","put","put","get","get","put","put","get","put","get","get","get","put","put","get","get","put","put","put","put","put","put","get","put","put","put","get","put","put","get","get","put","put","put","put","get","get","get","put","put","get","put","put","put","put","get","get","get","put","get","put","get","put","put","put","put","put","put","get","put","put","get","get","get","get","put","get","get","put","put","get","get","put","put","put","get","get","get","get","get","get","put","put","get","put","put","put","get","put","put","get","put","put","put","put","put","get","get","put","get","put","put","put","get","put","get","put","put","get","get","get","get","get","get","get","put","put","put","put","put","get","get","get","get","get","put","put","get","put","put","get","get","put","get","put","put","get","get","get","get","put","get","put","put","put","put","get","put","get","put","get","get","put","get","put","put","put","get","get","get","put","get","get","put","put","get","put","get","get","get","get","put","put","put","get","put","put","get","put","put","put","put","put","put","get","get","put","get","get","put","put","get","put","put","put","get","get","put","put","get","get","put","put","put","get","get","get","put","get","put","put","get","put","put","get","get","get","get","get","get","get","get","get","get","put","put","get","put","get","put","get","put","put","put","get","get","put","put","put","get","get","get","put","put","put","put","get","put","put","get","put","get","get","put","put","get","put","get","put","put","get","get","get","get","get","put","put","get","put","get","get","put","get","put","get","put","put","get","put","get","put","get","put","get","put","get","get","get","get","put","get","get","put","get","put","get","get","put","put","get","get","put","get","get","put","put","get","put","put","put","get","put","put","put","put","get","get","get","get","get","put","put","put","put","get","put","get","put","put","get","put","put","get","get","put","put","get","put","put","put","put","put","put","get","get","get","put","put","get","get","get","put","put","get","put","put","put","get","put","get","put","put","put","put","put","put","get","put","put","put","put","get","get","get","put","get","put","get","get","put","get","get","put","put","get","get","get","get","put","get","put","put","get","put","get","get","get","get","get","put","get","get","get","put","get","get","get","get","put","put","put","put","put","put","put","get","get","put","put","put","put","put","get","get","get","get","get","put","get","put","put","put","put","put","get","put","put","get","get","get","get","put","put","put","put","get","get","put","get","get","put","put","put","put","put","put","put","put","get","get","get","put","get","get","get","get","put","put","put","put","put","put","put","get","get","get","get","get","get","get","put","get","get","get","put","put","put","put","put","get","get","put","put","get","put","put","get","get","put","put","get","get","put","get","get","get","put","get","get","put","put","get","get","put","put","get","put","put","get","put","get","put","get","put","put","get","get","put","put","get","get","get","get","get","get","put","get","put","put","put","put","get","put","put","get","get","put","get","put","get","get","get","put","put","put","get","put","get","put","get","put","put","put","put","put","get","put","put","get","get","get","get","get","put","put","put","get","put","get","get","get","put","put","put","put","get","put","put","put","get","put","put","put","put","put","get","get","put","put","put","get","put","put","get","put","get","put","put","get","get","get","put","put","put","put","put","put","get","get","put","put","put","put","get","put","put","get","get","put","get","put","put","get","put","get","put","put","put","put","get","get","put","get","get","put","get","put","put","get","get","get","put","put","get","get","get","get","put","put","put","put","put","put","get","put","get","get","get","get","put","put","get","put","put","put","get","get","get","get","put","put","get","get","put","get","put","get","put","get","get","put","put","put","put","put","put","put","get","put","put","put","get","put","put","put","get","put","put","put","get","put","put","put","get","put","get","put","put","get","put","put","put","put","put","get","put","put","put","put","get","put","get","put","put","put","get","put","get","get","get","get","put","put","put","put","put","put","put","put","put","get","get","put","put","put","get","get","get","get","get","get","put","get","get","get","get","get","put","get","get","put","get","get","put","put","put","put","get","put","put","put","put","put","get","put","get","put","get","get","get","put","get","get","get","get","get","put","put","put","put","put","put","put","get","put","get","put","put","put","get","put","put","get","put","get","put","put","put","put","get","get","put","put","put","get","put","get","get","get","get","get","put","get","put","put","get","put","get","put","get","put","put","put","get","get","get","get","put","get","get","get","put","get","put","put","get","put","put","put","put","put","get","put","get","get","put","put","put","get","get","put","get","put","put","put","get","get","put","put","put","put","put","get","put","put","get","put","get","put","get","put","get","put","get","put","get","get","get","put","get","put","put","put","get","put","put","get","get","get","get","put","get","put","put","get","put","get","get","put","put","get","get","get","get","put","get","put","get","get","get","put","put","get","put","put","get","get","get","put","put","put","put","put","put","put","get","put","put","get","put","get","put","get","put","get","put","put","put","put","get","get","get","put","get","put","get","put","put","put","put","put","put","put","put","put","get","get","put","get","put","put","get","get","get","put","put","put","put","get","get","get","put","get","get","put","get","get","put","put","put","put","put","get","put","put","put","put","get","get","put","put","put","get","get","put","get","put","put","put","put","get","get","put","get","get","get","put","put","put","get","get","put","put","put","get","get","get","put","get","get","put","put","put","get","get","put","put","put","put","get","get","get","get","get","put","get","put","put","put","get","put","get","put","get","put","get","put","get","get","put","put","get","put","get","get","put","put","put","put","get","put","put","put","get","put","put","put","put","put","put","put","get","put","put","get","put","get","put","get","get","put","put","put","put","get","put","put","get","put","get","get","put","get","put","put","get","put","put","put","put","put","put","get","put","put","put","put","put","put","put","put","put","put","put","put","get","get","get","put","put","get","get","get","put","get","get","get","get","get","get","put","get","put","get","get","get","get","put","get","put","put","put","put","put","put","get","put","put","get","get","put","put","put","get","put","put","put","get","put","put","put","put","put","get","get","put","get","get","get","get","get","put","put","get","put","put","put","put","get","put","put","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","put","put","put","put","get","put","put","put","get","put","put","get","put","get","put","put","get","put","get","put","put","put","put","put","get","put","put","put","get","get","put","put","put","put","put","get","put","put","put","put","get","put","put","put","get","put","put","get","put","put","get","put","put","put","get","put","get","put","get","get","get","get","put","put","put","get","put","put","put","put","put","get","put","get","get","put","get","put","put","get","put","put","get","put","get","get","put","put","get","get","put","put","put","put","put","get","get","put","get","get","put","put","get","get","get","get","get","put","get","put","get","put","get","get","put","get","get","put","get","put","get","put","get","put","put","put","get","put","put","put","put","get","put","get","put","put","put","put","put","get","put","put","put","put","get","get","put","get","get","put","get","put","get","put","put","get","put","put","get","get","put","put","put","put","get","get","get","put","get","get","put","put","get","put","put","get","get","get","put","put","get","put","get","put","get","put","put","put","put","put","get","get","get","put","get","get","get","get","get","get","put","put","get","get","put","get","put","get","get","get","put","get","get","put","put","get","get","put","put","put","put","put","get","get","get","put","put","put","get","put","get","put","put","get","get","get","put","get","put","put","put","get","put","put","put","put","put","put","get","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","get","get","put","put","put","put","get","get","get","put","put","put","put","put","get","put","get","put","get","put","put","put","get","get","put","put","get","get","put","get","put","get","put","put","put","get","get","get","get","get","get","put","get","get","get","put","put","get","get","put","get","get","put","put","put","put","get","get","put","put","put","put","put","put","get","put","put","put","get","put","put","put","get","get","get","get","get","get","get","get","get","put","put","get","put","get","put","get","put","put","get","put","get","get","get","put","put","get","put","get","put","put","get","get","get","get","put","get","get","put","put","put","put","put","put","put","put","put","put","get","get","put","get","put","get","put","put","put","get","put","put","put","put","get","put","put","get","put","get","put","put","get","get","put","put","put","put","put","put","put","get","get","put","get","put","get","put","put","get","put","get","get","put","get","put","put","get","get","put","put","put","put","get","get","get","put","put","put","put","get","get","get","get","get","get","get","put","put","put","put","put","put","get","get","get","put","put","get","put","put","get","put","get","get","put","put","get","put","put","get","put","put","get","put","get","get","get","get","put","get","get","put","put","put","put","get","put","get","get","put","put","put","get","put","get","get","get","get","get","get","put","put","get","put","put","put","put","put","put","put","get","put","put","put","get","get","get","put","get","get","get","get","get","put","put","get","put","put","put","put","put","get","put","put","put","get","put","put","put","put","get","put","put","put","put","put","put","put","get","get","put","get","get","get","put","put","get","get","get","get","put","get","get","put","get","put","put","get","get","get","put","put","put","put","put","put","get","put","get","put","put","put","get","put","put","put","get","put","get","put","put","put","put","put","put","get","get","put","put","get","put","put","put","get","put","get","get","put","get","put","put","get","get","put","put","put","get","get","get","get","put","put","put","put","put","put","put","get","put","put","get","put"};
  std::vector<vector<int>> argumentList = {{512},{195,835},{494},{301,162},{36},{444},{138,1088},{200,1138},{335},{263},{26},{527},{337,98},{608,746},{158},{460,1226},{181},{31},{178,86},{71,1378},{584,362},{516,783},{230,172},{302,228},{654,1416},{217},{264,1118},{370},{7,228},{418},{199,1281},{56,1091},{18},{551},{512,1014},{459},{59,1491},{612},{64},{424,478},{68},{148},{167},{37},{451,237},{100,649},{19},{648},{641},{505,500},{505},{432,1286},{225},{1,533},{114},{9},{257,585},{467,629},{455,1348},{75,378},{473,1313},{101},{78},{221,1474},{435,344},{542},{433,161},{387,548},{377},{408,974},{106},{256},{208,1105},{426,731},{98,1247},{298},{283},{467,42},{263,277},{415,367},{197,780},{425},{428},{463,254},{622},{546,745},{383,398},{577,860},{335},{119},{311,407},{343},{325,1380},{571},{260},{373,72},{509,203},{189,583},{320},{490},{232,1374},{296,1303},{135,572},{7},{102,755},{238,361},{442,1152},{5},{361,1531},{76,892},{129},{649,1056},{33},{233},{322},{525},{403,336},{342,621},{660,1374},{158,69},{183},{250,630},{321},{33},{283,88},{479},{595},{598},{443,1013},{322,955},{363,127},{423},{546,1220},{45,19},{228,83},{364},{389,565},{108},{236,877},{6},{426},{589,1487},{478},{258,957},{187,1447},{582,1010},{296,583},{87,633},{198,907},{414},{514,945},{590},{458},{536,166},{4},{579,810},{452,237},{251,925},{436,1336},{524,957},{178},{329},{170},{221,539},{43,1300},{439,475},{425,576},{183,1437},{206,832},{329,863},{429},{630},{362,785},{637,117},{623},{11,215},{420},{529},{209},{336,161},{601,918},{349},{573},{551,163},{460,54},{513,508},{596,1153},{535,409},{190,752},{550},{533,888},{461,155},{507,623},{296},{363,48},{473,376},{59},{293},{357,650},{288,356},{30,125},{631,1090},{465},{20},{578},{652,527},{326,930},{21},{111,251},{132,817},{133,1118},{408,680},{244},{266},{458},{517,72},{128},{643,701},{409},{124,1183},{189,814},{585,25},{611,365},{167,118},{171,1189},{583},{172,93},{619,393},{424},{349},{163},{289},{560,1268},{337},{554},{176,285},{119,1282},{239},{646},{241,793},{284,1409},{491,259},{604},{593},{214},{272},{20},{126},{371,48},{251,780},{54},{529,1021},{211,1016},{511,142},{120},{584,976},{130,218},{106},{568,212},{115,60},{84,251},{610,1115},{500,1329},{226},{359},{159,853},{260},{552,202},{222,189},{369,510},{479},{209,810},{603},{454,643},{422,914},{54},{243},{273},{24},{113},{400},{134},{529,1137},{329,678},{535,498},{583,958},{547,357},{247},{373},{345},{329},{664},{4,117},{539,780},{501},{426,1},{201,1427},{648},{652},{283,407},{318},{440,720},{141,1426},{139},{228},{110},{525},{199,471},{401},{368,533},{30,1272},{406,1208},{370,1390},{217},{116,1237},{321},{486,827},{30},{423},{162,511},{363},{221,714},{433,328},{159,852},{563},{39},{61},{348,1532},{67},{12},{54,1004},{142,1502},{280},{622,476},{93},{40},{357},{649},{361,441},{256,465},{217,1058},{213},{606,433},{448,426},{174},{449,607},{84,843},{564,1254},{46,1162},{176,657},{618,221},{373},{437},{436,466},{485},{130},{14,1136},{467,1376},{243},{49,610},{260,927},{299,1337},{425},{150},{369,1408},{294,247},{636},{59},{361,937},{485,1275},{272,853},{18},{228},{132},{81,351},{141},{43,657},{113,1229},{361},{520,1104},{346,1194},{605},{545},{277},{417},{45},{8},{210},{574},{340},{95},{363,1466},{387,872},{96},{516,792},{474},{200,643},{70},{284,135},{224,723},{198,688},{381},{17},{582,77},{398,724},{594,418},{548},{232},{422},{294,1060},{238,571},{222,1400},{312,248},{56},{495,1262},{47,328},{33},{406,1522},{126},{262},{403,986},{214,284},{454},{563,398},{286},{150,891},{313,1113},{81},{531},{160},{8},{236},{389,1258},{104,586},{101},{124,641},{616},{70},{241,921},{485},{88,1058},{448},{229,1342},{635,561},{570},{3,266},{245},{579,399},{598},{643,1309},{581},{179,198},{374},{486},{337},{87},{59,584},{397},{80},{422,1331},{96},{627,24},{516},{369},{188,43},{325,303},{181},{346},{379,463},{176},{113},{580,110},{57,218},{114},{530,166},{464,1524},{377,1342},{487},{230,829},{642,578},{193,663},{74,1338},{502},{520},{17},{573},{127},{51,934},{291,1491},{154,1412},{609,359},{658},{320,27},{392},{649,10},{197,1199},{156},{366,13},{315,126},{614},{59},{436,549},{155,1118},{42},{64,1027},{123,359},{510,955},{643,370},{9,505},{577,110},{78},{594},{151},{573,1266},{369,122},{506},{580},{94},{451,572},{460,154},{381},{244,654},{481,297},{119,650},{259},{471,311},{115},{598,1237},{41,973},{510,82},{448,701},{22,49},{579,1138},{328},{75,1134},{632,725},{139,706},{101,1406},{520},{105},{11},{214,392},{574},{116,1398},{532},{559},{289,34},{184},{655},{613,1532},{490,1121},{34},{227},{423},{395},{572,879},{655},{654,726},{499,812},{72},{334,272},{494},{385},{359},{478},{199},{413,1071},{173},{451},{531},{607,1535},{212},{541},{508},{289},{99,1386},{73,1285},{567,288},{657,1137},{144,1498},{184,241},{473,1243},{182},{584},{71,1337},{377,995},{179,470},{590,1211},{15,573},{35},{424},{498},{570},{412},{439,161},{453},{261,475},{265,1169},{599,1111},{549,1068},{593,328},{245},{459,295},{285,958},{187},{546},{128},{247},{661,1275},{423,1280},{411,533},{649,936},{199},{627},{374,38},{252},{121},{629,625},{261,770},{501,1048},{403,725},{412,249},{642,872},{213,538},{408,141},{142},{514},{500},{486,85},{344},{158},{614},{589},{647,1456},{621,495},{574,1125},{230,604},{474,3},{282,813},{506,92},{423},{494},{80},{206},{436},{18},{652},{173,655},{545},{601},{72},{482,935},{68,1032},{136,47},{375,881},{34,693},{644},{309},{139,1082},{60,1255},{631},{238,612},{300,90},{7},{518},{96,456},{536,801},{659},{351},{584,160},{388},{158},{99},{603,812},{200},{121},{259,437},{155,199},{339},{25},{57,999},{387,1499},{201},{485,56},{483,862},{612},{382,1327},{15},{465,746},{156},{70,825},{497,96},{584},{544},{187,832},{523,316},{337},{304},{533},{294},{22},{24},{460,72},{233},{459,974},{414,1000},{601,464},{306,1200},{364},{371,681},{633,430},{54},{453},{334,878},{29},{62,803},{464},{616},{456},{409,889},{60,1207},{335,1479},{26},{526,732},{350},{318,893},{478},{130,157},{178,584},{241,294},{266,548},{38,62},{276},{1,972},{331,434},{480},{92},{482},{21},{648},{242,588},{438,922},{126,250},{149},{559,372},{468},{272},{650},{129,490},{590,549},{67,471},{153,24},{42},{262,921},{181,504},{242,1042},{339},{235,352},{90,421},{436,217},{47,469},{449,760},{599},{135},{35,1221},{148,1377},{529,1273},{501},{42,255},{430,1131},{251},{128,1011},{514},{399,446},{663,529},{326},{197},{647},{342,1441},{611,239},{429,1397},{146,1172},{466,873},{23,586},{175},{462},{312,735},{90,641},{11,101},{501,974},{573},{208,1495},{518,1235},{288},{492},{616,1094},{352},{15,402},{305,607},{603},{640,1274},{43},{122,1271},{86,70},{532,109},{325,143},{587},{207},{559,1143},{537},{491},{156,192},{560},{545,479},{390,936},{307},{497},{567},{571,655},{422,1050},{35},{162},{585},{173},{198,1062},{636,726},{552,1048},{424,1535},{138,828},{28,602},{126},{498,79},{428},{143},{218},{94},{616,156},{82,138},{30},{354,186},{134,971},{102,575},{464},{113},{322},{33},{507,823},{655,442},{67},{407},{190,260},{315},{470,953},{603},{420,448},{348},{365},{548,367},{226,741},{286,81},{367,805},{37,722},{527,348},{517,1407},{177},{119,300},{25,1234},{296,459},{3},{43,886},{79,684},{638,388},{284},{168,353},{124,1171},{89,436},{596},{280,1109},{142,651},{400,446},{650},{535,326},{247},{414,867},{122,1421},{428},{538,1047},{346,1441},{481,1236},{282,230},{465,787},{649},{429,1120},{218,772},{291,116},{359,1419},{265},{648,581},{351},{85,1099},{16,1074},{477,606},{651},{615,901},{361},{606},{550},{409},{602,823},{154,291},{658,704},{530,580},{233,1396},{403,891},{555,839},{47,460},{458,347},{599},{67},{597,493},{217,868},{290,63},{9},{398},{311},{313},{454},{369},{636,81},{114},{256},{432},{125},{145},{584,540},{390},{313},{382,497},{512},{273},{552,755},{367,1327},{52,348},{32,21},{511},{458,1496},{583,611},{528,134},{253,1010},{471,903},{330},{642,364},{351},{302,709},{434},{76},{159},{544,1492},{104},{560},{228},{266},{187},{66,693},{483,1467},{123,27},{71,1221},{319,587},{653,1350},{498,931},{281},{346,919},{299},{109,634},{266,1291},{207,1256},{509},{435,595},{426,28},{658},{329,599},{644},{236,1470},{13,1291},{627,2},{76,350},{123},{72},{129,567},{175,608},{432,1279},{87},{291,1506},{503},{149},{599},{183},{590},{9,380},{169},{74,1133},{220,1088},{322},{585,837},{224},{186,1353},{444},{161,1351},{419,1064},{584,1495},{202},{261},{623},{543},{370,359},{361},{599},{565},{631,286},{622},{324,912},{146,199},{38},{230,652},{252,699},{409,10},{81,1161},{623,996},{103},{149,721},{442},{58},{525,1145},{217,320},{186,1525},{35},{224},{111,1008},{470},{314,948},{12,1435},{373,605},{531},{622},{187,687},{570,986},{516,97},{187,1410},{129,725},{342},{542,110},{643,1295},{427},{423,1076},{225},{192,1497},{45},{568,691},{460},{154,1035},{639},{116,759},{46},{400},{497},{264,224},{2},{649,970},{593,1501},{345,376},{514},{663,1106},{160,1147},{568},{564},{166},{323},{32,1270},{205},{154,1458},{20,1114},{489},{29,741},{461},{53},{573,367},{130,1388},{575},{480},{463},{247},{576,804},{310},{81,251},{323},{126},{168},{80,289},{6,514},{245},{334,1301},{652,908},{439},{72},{457},{636,1006},{69,647},{224,811},{216,587},{44,676},{398,70},{370,1522},{583},{570,887},{157,752},{359},{506,528},{353},{368,61},{37},{117,848},{574},{138,876},{469,1353},{297,107},{201,137},{519},{544},{180},{132,1358},{410},{123,1494},{520},{20,1468},{401,387},{150,840},{415,1127},{489,62},{553,1019},{264,357},{179,1520},{604,1032},{7},{492},{79,566},{460},{145,91},{241,1293},{306},{364},{391},{104,565},{242,412},{553,599},{377,416},{278},{631},{596},{2,1447},{5},{602},{207,990},{309},{314},{436,126},{145,685},{88,368},{371,922},{659,320},{472},{546,1164},{52,797},{481,226},{315,898},{590},{162},{589,975},{204,305},{114,353},{186},{52},{222,62},{377},{266,147},{651,540},{371,96},{183,1011},{385},{213},{536,1017},{131},{574},{414},{490,243},{370,53},{640,1063},{416},{264},{153,916},{556,278},{462,1122},{457},{637},{20},{176,601},{140},{357},{560,330},{548,1103},{127,811},{47},{337},{528,753},{225,1089},{58,1536},{595,331},{457},{531},{265},{87},{41},{432,452},{357},{129,770},{243,866},{296,85},{186},{624,885},{273},{103,853},{382},{315,1006},{218},{567,605},{51},{317},{583,1255},{556,1254},{311},{325,1018},{261},{113},{574,569},{88,1214},{422,746},{374,934},{11},{248,484},{383,90},{209,195},{394},{122,1452},{581,1415},{524,811},{59,933},{642,1437},{662,435},{358,261},{208},{264,236},{368,1368},{58},{146,475},{62},{452,523},{210},{105},{89,1231},{342,259},{562,1426},{448,657},{612},{561,669},{344,1293},{309},{130,885},{259},{543},{161,425},{409},{376,1513},{142,396},{594},{508,928},{457,1505},{46,1252},{64,1290},{498,1224},{30,123},{354},{50,349},{358,637},{625,233},{258,117},{567,308},{222,735},{333,54},{361,451},{547,188},{145,250},{120,667},{464,694},{119},{596},{150},{582,524},{212,794},{33},{480},{199},{33,444},{224},{81},{84},{72},{622},{461},{617,26},{456},{262,351},{599},{244},{108},{184},{92,347},{492},{160,1270},{536,319},{462,1499},{329,1511},{489,600},{286,882},{481},{313,213},{13,1},{129},{199},{246,517},{565,1239},{160,617},{100},{519,119},{5,450},{118,1172},{565},{200,1160},{198,104},{499,481},{359,520},{120,956},{71},{233},{524,362},{631},{75},{449},{651},{42},{640,1053},{360,1303},{309},{77,341},{228,1392},{297,663},{191,894},{323},{480,508},{574,288},{595},{84},{160,1243},{249,780},{447,1111},{90},{512,1037},{92},{51},{515,540},{643,938},{112},{617,104},{246,612},{376,777},{665,166},{592,613},{180,1213},{207,908},{428,1197},{150},{430,527},{509,1181},{663,831},{637},{202,127},{247,1434},{414},{2,721},{178},{484,818},{579,1244},{179},{482,1129},{206},{346,1456},{480,334},{298,47},{209,250},{484,505},{90},{207,205},{15,595},{105,1326},{245},{446},{380,276},{533,1135},{332,1165},{196,1118},{332,527},{312},{90,916},{410,139},{626,986},{591,1506},{102},{481,856},{89,209},{120,1091},{568},{13,913},{456,297},{234},{195,432},{159,1486},{535},{250,737},{91,29},{399,1281},{628},{620,290},{284},{386,814},{427},{344},{95},{179},{221,1033},{197,1186},{613,646},{616},{559,1399},{371,1330},{435,1530},{483,132},{372,403},{578},{56,1301},{612},{67},{251,222},{352},{204,1280},{150,15},{296},{619,397},{339,1123},{417},{321,112},{562},{451},{30,989},{91,746},{291},{219},{43,1059},{526,553},{274,241},{162,172},{234,746},{457},{333},{650,856},{541},{647},{93,1387},{17,208},{403},{527},{143},{183},{392},{456,291},{16},{472,998},{595},{229,303},{617},{76},{552,341},{485},{196},{426,853},{575},{497,582},{396},{397,1531},{154},{203,767},{630,838},{173,1100},{431},{466,403},{193,269},{466,628},{556,1054},{400},{372,1498},{102},{414,45},{214,1474},{213,553},{142,520},{507,531},{337},{15,1131},{179,1415},{328,1480},{582,607},{601},{437},{508,1446},{342},{267},{125,148},{331},{463,1401},{188},{255,1405},{549,1304},{156},{29,896},{545,999},{468},{508},{23,883},{375,366},{531,719},{310,477},{127},{224},{661},{148,90},{142},{423},{161,13},{85,1301},{232},{114,101},{565,506},{441},{621},{300},{577,1211},{492,1351},{258},{610,1093},{497},{135,1309},{417},{648,449},{429,90},{239,1392},{33,162},{217,534},{110},{244},{284},{231,229},{393},{406},{458},{112},{608},{408},{291,360},{303,806},{271},{111},{395,3},{542},{621,1153},{257},{11},{141},{308,851},{252},{170},{517,649},{397,200},{537},{547},{220,704},{36,8},{113,1362},{397,884},{59,1328},{332},{449},{220},{558,1277},{515,1505},{468,993},{659},{570,212},{659},{624,103},{233,1311},{282},{217},{521},{651,89},{115},{542,1203},{513,1274},{163,1402},{562},{171,752},{269,1427},{120,124},{156,1412},{659,273},{27,430},{187},{171,1139},{438,918},{184},{608,831},{517,641},{410},{602,633},{168},{512},{255},{96,617},{46},{5},{629,881},{595,614},{307},{73},{371,171},{323,1193},{246,216},{500,1278},{419},{526},{542},{275,1418},{407,598},{564,873},{11,1268},{188,908},{375},{382,946},{256},{511,202},{461},{84,858},{275,1036},{116,1358},{161},{309},{61,149},{73,1181},{235},{629},{91,1434},{533},{429,1331},{627},{80,801},{202,104},{503,199},{365},{477},{40},{201},{354},{381},{193,1110},{519},{8},{177},{562,692},{256,481},{67},{525},{84,319},{312},{129},{510,807},{83,1526},{41,1328},{162,205},{128},{358},{191,1433},{191,558},{440,214},{321,947},{640,672},{417,1032},{158},{346,1019},{139,718},{613,616},{385},{173,421},{38,590},{519,524},{572},{8},{39},{369},{588},{214},{466},{56},{114},{65,381},{614,1014},{597},{291,1491},{664},{390,837},{375},{447,203},{599,982},{559},{48,1122},{368},{205},{618},{299,1357},{170,968},{451},{36,1442},{611},{57,1433},{595,942},{52},{445},{91},{351},{603,826},{280},{261},{86,627},{412,534},{238,941},{575,570},{23,1312},{479,161},{209,347},{599,1252},{591,336},{338,970},{139},{184},{462,418},{246},{142,383},{533},{77,851},{25,1042},{252,1470},{160},{154,754},{482,565},{156,125},{653,126},{119},{48,1132},{135,636},{346},{427,18},{42},{22,993},{316,757},{375},{219},{238,80},{429,427},{119,1245},{180,1466},{233,1399},{571,1103},{37,671},{56},{564},{478,353},{360},{194,827},{420},{383,1446},{207,1275},{213},{116,951},{98},{193},{132,364},{386},{542,931},{115,1445},{333},{28},{65,979},{522,1074},{197,878},{218,780},{262},{48},{651},{505,1529},{343,184},{284,715},{579,1019},{624},{39},{152},{663},{33},{395},{514},{379,889},{488,674},{535,996},{115,1316},{405,1445},{521,578},{59},{177},{542},{584,691},{648,55},{507},{113,417},{160,702},{393},{463,1249},{152},{300},{443,1073},{537,277},{538},{596,635},{205,1285},{531},{533,149},{204,1076},{300},{41,591},{179},{64},{492},{649},{306,932},{225},{79},{140,59},{577,468},{99,990},{594,1398},{489},{636,585},{346},{323},{560,531},{417,697},{176,292},{407},{635,1413},{202},{49},{558},{342},{598},{206},{247,1013},{655,425},{72},{196,1339},{425,158},{139,816},{102,956},{181,867},{591,139},{250,719},{475},{342,71},{653,11},{35,577},{231},{431},{284},{507,1235},{26},{60},{229},{423},{614},{332,359},{407,140},{105},{20,636},{74,739},{544,1283},{144,1273},{215,295},{3},{453,873},{614,132},{249,10},{649},{33,376},{188,787},{590,1057},{356,998},{258},{65,58},{263,359},{20,1166},{319,885},{373,612},{432,764},{84,523},{463},{523},{8,196},{454},{83},{561},{76,384},{115,1036},{348},{120},{107},{248},{488,134},{304},{341},{143,696},{547},{520,1042},{368,1376},{232},{579},{583},{430,459},{21,713},{458,88},{60,697},{32,427},{245,340},{59},{477,904},{107},{103,754},{438,142},{51,744},{467},{235,166},{339,1219},{621,1308},{509},{489,1091},{183},{108,95},{492,1084},{533,578},{445,32},{510,1488},{347,965},{68},{470},{382,941},{429,1413},{1},{34,1428},{292,1243},{506,1137},{305},{6,64},{115},{420},{45,292},{218},{642,412},{165,1509},{564},{465},{538,614},{267,899},{474,117},{646},{473},{386},{356},{535,37},{295,631},{79,1414},{612,1253},{215,1352},{21,1450},{25,141},{1},{253,655},{651,400},{465},{647,101}};
  auto it_arg = argumentList.begin();
  LRUCache* pCache = nullptr;
  for( auto it = vecOperation.begin() ; it != vecOperation.end(); ++it)
  {
    if ( *it == "LRUCache")
    {
      pCache = new LRUCache(it_arg->at(0));
    }
    if (*it == "put")
    {
      pCache->put(it_arg->at(0), it_arg->at(1));
    }
    if (*it == "get")
    {
      pCache->get(it_arg->at(0));
    }
  it_arg++;
  }
  //NodeNxt *pResultList = create_tree_ptr({1,-99,2,-99,3,-99,4,-99,5,-99,6});
  /**
  while( pInputList!= nullptr) {
    BOOST_CHECK_EQUAL( pInputList->val, pResultList->val);
    pInputList= pInputList->right;
    pResultList = pResultList->right;
  }
  */
}

TEST (test_geeks_solver, splitList)
{
  List* pInputList = create_link_list({1,2,3,4,5,6,7,8,9,10});
  std::vector<List*> vecRetList = splitListToParts(pInputList, 3);
}

TEST (test_geeks_solver, distinctSubstring) 
{
  std::string sInputString = "xyzzaz";
  int nCount = countGoodSubstrings(sInputString);
  BOOST_CHECK_EQUAL(nCount, 1);
  sInputString = "aababcabc";
  nCount = countGoodSubstrings(sInputString);
  BOOST_CHECK_EQUAL(nCount, 4);
}
TEST (test_geeks_solver, longestValidSubstring) 
{
//  std::string sInputString = "YazaAay";
 // std::string sOutputString = longestNiceSubstring(sInputString);
}
TEST (test_geeks_solver, lengthLongestSubstring) 
{
  std::string sInputString = "abba";
  int nLongest;
  //nLongest = lengthOfLongestSubstring(sInputString);
  //BOOST_CHECK_EQUAL(nLongest, 2);
  sInputString = "tmmzuxt";
  nLongest = lengthOfLongestSubstring(sInputString);
  BOOST_CHECK_EQUAL(nLongest, 5);
  sInputString = "bbbbb";
  nLongest = lengthOfLongestSubstring(sInputString);
  BOOST_CHECK_EQUAL(nLongest, 1);
  sInputString = "abcabcbb";
  nLongest = lengthOfLongestSubstring(sInputString);
  BOOST_CHECK_EQUAL(nLongest, 3);
}

TEST (test_geeks_solver, jump_game)
{
  std::vector<int> nums = {1,2};
  int nMinJump;
  nMinJump = jump(nums); 
  BOOST_CHECK_EQUAL( nMinJump, 1);

  nums = {2,1};
  nMinJump = jump(nums); 
  BOOST_CHECK_EQUAL( nMinJump, 1);

  nums = {3,2,1};
  nMinJump = jump(nums); 
  BOOST_CHECK_EQUAL( nMinJump, 1);

  nums = {2,3,1,1,4};
  nMinJump = jump(nums); 
  BOOST_CHECK_EQUAL( nMinJump, 2);
}

TEST (test_geeks_solver, is_valid_bst)
{

}

TEST(test_geeks_solver, merge_interval)
{

}

TEST(test_geeks_solver, merge_sort_array)
{
  std::vector<int> num1 = {0}; 
  std::vector<int> num2 = {1}; 
  merge(num1, 0, num2, 1);
}

TEST(test_geeks_solver, resolve_ip_address)
{
  std::string s = "25525511135";
  std::set<string> resultValidIP = restoreIpAddresses(s);
}
TEST(test_geeks_solver, remove_dublicate)
{
  //std::vector<int> nums = {0,0,1,1,1,1,2,3,3,3,4,4,5,5};
  //std::vector<int> nums = {0,0,1,1,1,1,2,3,3};
  std::vector<int> nums = {1,1,1};
 // std::vector<int> nums ={1,1,1,2,2,3};
  //std::vector<int> nums = {0,0,0,0,0,1,2,2,3,3,4,4};
  int nShift  =  removeDuplicates(nums);
  std::cout << "shift are " << nShift << std::endl;

  std::for_each(nums.begin(), nums.end(), [](int x){
      std::cout << " " << x ;
      })
  BOOST_CHECK_EQUAL(nShift, 4);

}
TEST(test_geeks_solver, remove_element)
{
  std::vector<int> nums = {1, 33 };
  int nVal = 2;
  int nSize = removeElement(nums, nVal);
  BOOST_CHECK_EQUAL(nSize, 4);
}

TEST(test_geeks_solver, remove_element_sorted)
{
  std::vector<int> nums = {1,1,2};
  int nSize = removeDuplicatesSorted(nums);
  for_each(nums.begin(), nums.end(), [](int x)
      {
        std::cout << x << " "; 
      });
  BOOST_CHECK_EQUAL(nSize , 1);
}

TEST(test_geeks_solver, majority_element)
{
  std::vector<int> nums = {8,8,7,7,7};
  int nElement = majorityElement(nums);
  EXPECT_EQ(nElement, 3);
}

TEST(test_geeks_solver, rotate_array)
{
  std::vector<int> nums = {3, 5, 12, 6, 8,43, 19};
  rotate(nums, 4);
}

TEST(test_geeks_solver, buy_sell_stock_1)
{
  std::vector<int> prices = { 7,1,5,3,6,4 };
  int nProfit = maxProfitOnce(prices);
}

TEST(test_geeks_solver, buy_sell_stock_2)
{
  std::vector<int> prices = { 7,1,5,3,6,4 };
  int nProfit  = maxProfit(prices);
}
