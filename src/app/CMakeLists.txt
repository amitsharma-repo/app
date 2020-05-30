cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")

project(feature_app)
target_include_directories(feature_app
     PUBLIC
     ${CORE_DIR}/include
     ${APP_DIR}/include
     )
target_link_libraries(feature_app
     PRIVATE
     core
     Threads::Threads
     )

add_executable(
	feature_app
	feature_app.cpp
	)
	
install(TARGETS feature_app
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
