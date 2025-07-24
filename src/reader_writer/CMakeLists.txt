set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_VERBOSE_MAKEFILE ON)
project(reader_writer)


 #adding libarry as libApp
 add_library(reader_writer STATIC 
     reader_writer.cpp
     reader_writer_starvefree.cpp
     reader_writer_fast.cpp
     reader_writer_lockfree.cpp
     #image_rotate.cpp
     #count_number_of_atoms.cpp
     )
 target_link_libraries(reader_writer
     PRIVATE
         core
     )
target_include_directories(reader_writer
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR} ../../include/reader_writer/
   )
 
 #set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build/install)
install(TARGETS reader_writer  
     DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
 #install(TARGETS feature_app
 #    DESTINATION ${CMAKE_INSTALL_PREFIX}
 #    )
