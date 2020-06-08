cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(application)

#adding executable as feature_app
add_executable(application
	feature_app.cpp
	)
target_include_directories(application
      PUBLIC
      ${CORE_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR} ../../include 
      )
target_link_libraries(application
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
 install(TARGETS application
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 
