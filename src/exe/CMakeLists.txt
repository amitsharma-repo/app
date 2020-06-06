cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(app_exe)

#adding executable as feature_app
add_executable(feature_app
	feature_app.cpp
	)
target_include_directories(feature_app
      PUBLIC
      ${CORE_DIR}/include
      ${APP_DIR}/include
      )
target_link_libraries(feature_app
     PRIVATE
     core
     )
 install(TARGETS feature_app 
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 
