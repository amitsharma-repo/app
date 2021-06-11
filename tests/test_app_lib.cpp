#pragma once
#include<tuple>
#include<avoid_flood_in_city.h>
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
#include<iostream>
#include<TestMain.cpp>
#include<util_struct.h>
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
    std::cout << "{ 5,0,3,8,6 }" << std::endl;
    int n_partition_index = find_partition_array_into_disjoint_interval( input_data );
    BOOST_CHECK_EQUAL( n_partition_index, 3 );
    input_data = { 1,1,1,0,6,12 };
    std::cout << "{ 1,1,1,0,6,12 }" << std::endl;
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
