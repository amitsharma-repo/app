if(USE_GOOGLE_TEST)
	include(GoogleTest)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD YES)
set(THREAD_PREFER_PTHREAD_FLAG YES)
find_package(Threads REQUIRED)

add_Executable(test_app_lib test_app_lib.cpp
    )
target_include_directories(test_app_lib
    PUBLIC
    ${CORE_DIR}/src/testMain
	${CORE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR} ../include/ 
    )   
target_link_libraries(test_app_lib
    PUBLIC
	core::framework_test
    geeks_solver 
    core
	Threads::Threads
	)	
add_tests(test_app_lib LABELS "app_lib")

