set(CMAKE_THREAD_PREFER_PTHREAD YES)
set(THREAD_PREFER_PTHREAD_FLAG YES)
find_package(Threads REQUIRED)

add_Executable(test_sample test_sample.cpp)
target_include_directories(test_sample
    PUBLIC
    ${CORE_DIR}/src/testMain
	${CORE_DIR}/include
	${APP_DIR}/include
    )   
target_link_libraries(test_sample
	PRIVATE
	core::framework_test
	core
	Threads::Threads
	)	
add_tests(test_sample LABELS "app")

