cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(application)

#adding executable as feature_app
add_executable(feature_app
	feature_app.cpp
	)
target_include_directories(feature_app
      PUBLIC
      ${CORE_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR} ../../include 
      )
target_link_libraries(feature_app
     PRIVATE
     )
 install(TARGETS feature_app 
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 
