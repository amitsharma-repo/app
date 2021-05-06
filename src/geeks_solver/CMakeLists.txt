cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(geeks_solver)


 #adding libarry as libApp
 add_library(geeks_solver STATIC 
     find_max_area_of_container.cpp
     check_larry_array.cpp
     calculate_3d_surface_area.cpp
     partition_array_into_disjoint_interval.cpp
     min_flip_for_monotone_increasing.cpp
     reverse_digit_integer.cpp
     binary_search_to_greater_sum.cpp
     string_to_integer.cpp
     pair_with_sum_from_two_subarray.cpp
     duplicate_sub_tree.cpp 
     triplet_with_zero_sum.cpp
     jumping_number.cpp
     find_last_element_in_complete_binary_tree.cpp
     longest_valid_parantheses.cpp
     maximum_index.cpp
     find_subarray_with_given_sum.cpp
     find_sets_with_last_occurance.cpp
     connect_node_at_same_level.cpp
     #     binary_tree_utils.cpp
     utils.cpp
     delete_node_with_greater_on_right.cpp
     find_duplicate_in_n_time.cpp
     find_smallest_range_from_klist.cpp 
     shortest_reach.cpp
     find_first_in_rotated_sorted_arr.cpp 
     #     level_order_spiral_traversal.cpp
     find_min_number_from_given_sequence.cpp
     )
 target_link_libraries(geeks_solver
     PRIVATE
         core
     )
target_include_directories(geeks_solver
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR} ../../include
   )
 
 #set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build/install)
install(TARGETS geeks_solver  
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 #install(TARGETS feature_app
 #    DESTINATION ${CMAKE_INSTALL_PREFIX}
 #    )
