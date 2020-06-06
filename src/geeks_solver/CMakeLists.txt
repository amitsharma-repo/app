cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(geeks_solver)


 #adding libarry as libApp
 add_library(App_lib STATIC find_smallest_range_from_klist.cpp)
 target_link_libraries(App_lib
     PRIVATE
         core
     )
target_include_directories(App_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR} ../../include
   )
 
 #set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build/install)
install(TARGETS App_lib 
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 #install(TARGETS feature_app
 #    DESTINATION ${CMAKE_INSTALL_PREFIX}
 #    )
