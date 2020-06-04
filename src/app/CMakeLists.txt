cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")

project(app)

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
 
 #adding libarry as libApp
 add_library(App_lib)
target_sources(App_lib
    PUBLIC
    find_samllest_range_from_klist.cpp
    )
target_link_libraries(App_lib
    PRIVATE
    core
    )
target_include_directories(App_lib
    PUBLIC
    ${CORE_DIR}/include
    ${APP_DIR}/include
    )
install(TARGETS App_lib 
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
install(TARGETS feature_app
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
