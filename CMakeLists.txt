cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(app
	LANGUAGES C CXX)

enable_testing()

include(cmake/project_Setting.cmake)
# proejct wide setup
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(Test)
include(CTest)

if (NOT DEFINED CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
option(BUILD_SHARED_LIBS
	"build all libarry as shared libraries instead of static" ON)

option(TEST_APP "Enable APP unit tests" ON)
option(USE_GOOGLE_TEST "Enable Google tests" ON)                               

if(USE_GOOGLE_TEST)
	add_definitions( -DUSE_GOOGLE_TEST=1 )                             
else()
	add_definitions( -DUSE_GOOGLE_TEST=0 )                             
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CORE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../core)
set(APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../app)
set(CMAKE_INSTALL_PREFIX ${APP_DIR}/build/install)
if(TEST_APP OR CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
     set(TEST_APP ON CACHE BOOL "Enable app unit tests" FORCE)
     add_subdirectory(tests)
endif()

add_subdirectory(src)
add_subdirectory(external)
add_subdirectory(dependencies)

