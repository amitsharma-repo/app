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
add_library(libApp)
target_sources(libApp
    PUBLIC
    find_samllest_range_from_klist.cpp
    )
#target_include_directories(libApp
#    (
#    PUBLIC
#    ${CORE_DIR}/include
#    ${APP_DIR}/include
#    )
target_link_libraries(libApp
    PRIVATE
    core
    )

install(TARGETS libApp 
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
install(TARGETS feature_app
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
