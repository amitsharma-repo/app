cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(geeks_solver)


 #adding libarry as libApp
 add_library(geeks_solver STATIC 
     find_smallest_range_from_klist.cpp 
     shortest_reach.cpp
     find_first_in_rotated_sorted_arr.cpp 
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
