if(USE_GOOGLE_TEST)
	include(GoogleTest)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD YES)
set(THREAD_PREFER_PTHREAD_FLAG YES)
find_package(Threads REQUIRED)

add_Executable(test_sample test_sample.cpp
    )
target_include_directories(test_sample
    PUBLIC
    ${CORE_DIR}/src/testMain
	${CORE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR} ../include/ 
    )   
target_link_libraries(test_sample
    PUBLIC
	core::framework_test
    App_lib
    core
	Threads::Threads
	)	
add_tests(test_sample LABELS "app")

