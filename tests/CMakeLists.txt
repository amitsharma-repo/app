if(USE_GOOGLE_TEST)
	include(GoogleTest)
endif()

set(CMAKE_THREAD_PREFER_PTHREAD YES)
set(THREAD_PREFER_PTHREAD_FLAG YES)
find_package(Threads REQUIRED)

add_Executable(test_dsa_problems TestDSAProblems.cpp)

target_include_directories(test_dsa_problems
    PUBLIC
    ${CORE_DIR}/src/testMain
	  ${CORE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR} ../include/ 
)   
target_link_libraries(test_dsa_problems
    PUBLIC
	  core::framework_test
    geeks_solver 
    core
	  Threads::Threads
)


add_Executable(test_reader_writer TestReaderWriter.cpp)

target_include_directories(test_reader_writer
    PUBLIC
    ${CORE_DIR}/src/testMain
	  ${CORE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR} ../include/ 
)   
target_link_libraries(test_reader_writer
    PUBLIC
	  core::framework_test
    geeks_solver 
    core
	  Threads::Threads
)	

add_tests(test_dsa_problems LABELS "testDSA")
add_tests(test_reader_writer LABELS "testReaderWriter")

