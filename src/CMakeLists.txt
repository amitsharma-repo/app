cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(app)

#adding executable as feature_app
#add_executable(feature_app
#	feature_app.cpp
#	)
#target_include_directories(feature_app
#      PUBLIC
#      ${CORE_DIR}/include
#      ${APP_DIR}/include
#      )
#target_link_libraries(feature_app
#     PRIVATE
#     core
#     )
 
 #adding libarry as libApp
 add_library(App_lib STATIC find_smallest_range_from_klist.cpp)
 #target_sources(App_lib
 #    PUBLIC
 #    find_samllest_range_from_klist.cpp
 #    )
 #target_link_libraries(App_lib
 #    PRIVATE
 #    #    core
 #    )
target_include_directories(App_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
   )
 #set_target_properties(App_lib PROPERTIES
 #        OUTPUT_NAME App_lib
 #        )
 
 #set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build/install)
install(TARGETS App_lib 
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 #install(TARGETS feature_app
 #    DESTINATION ${CMAKE_INSTALL_PREFIX}
 #    )
