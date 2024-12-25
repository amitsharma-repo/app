cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(geeks_solver)


 #adding libarry as libApp
 add_library(geeks_solver STATIC 
     count_and_say.cpp
     find_first_and_last_position_of_element.cpp
     search_in_rotated_array.cpp
     reverse_nodes_in_k_group.cpp
     swaping_nodes_in_linklist.cpp
     remove_nth_node_from_end.cpp
     populating_nxt_right_pointer.cpp
     min_jump_to_reach_home.cpp
     avoid_flood_in_city.cpp
     find_circular_loop.cpp
     generate_parantheses.cpp
     letter_combination_of_phone_number.cpp
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
     partition_list.cpp
     partition_smallerValue.cpp 
     rotate_list.cpp
     add_two_number_list.cpp
     reverse_link_list.cpp
     sortedListToBST.cpp
     flatten_binary_tree.cpp
     next_rightptr_tree.cpp
     reverse_link_list_between_position.cpp
     LRU_Cache.cpp
     split_linked_list.cpp
     distinct_substring_of_size_n.cpp
     longest_nice_substring.cpp
     longest_substr_without_repeat.cpp
     jump_game.cpp
     isValidBST.cpp
     restoreIPAddress.cpp
     #merge_interval.cpp
     merge_sort_array.cpp
     #image_rotate.cpp
     #count_number_of_atoms.cpp
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
