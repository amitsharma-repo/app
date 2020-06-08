cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(application)

#adding executable as find_smallest_range_app
add_executable(find_smallest_range_app
	find_smallest_range_app.cpp
	)
target_include_directories(find_smallest_range_app
      PUBLIC
      ${CORE_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR} ../../include 
      )
target_link_libraries(find_smallest_range_app
     PRIVATE
     geeks_solver
     )


 #test application for shortest reach
add_executable(shortest_reach_app
    shortest_reach_app.cpp
	)
target_include_directories(shortest_reach_app
      PUBLIC
      ${CORE_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR} ../../include 
      )
target_link_libraries(shortest_reach_app
     PRIVATE
     geeks_solver
     )
 

 #adding execuatobe for graph_app
 add_executable(graph_app
	graph_app.cpp
	)
target_include_directories(graph_app
      PUBLIC
      ${CORE_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR} ../../include 
      )

 install(TARGETS graph_app
     DESTINATION ${CMAKE_INSTALL_PREFIX}
     )
 
 install(TARGETS shortest_reach_app
     DESTINATION ${CMAKE_INSTALL_PREFIX}
     )
 install(TARGETS find_smallest_range_app
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 
