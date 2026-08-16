# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/../core")
  file(MAKE_DIRECTORY "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/../core")
endif()
file(MAKE_DIRECTORY
  "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-build"
  "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-subbuild/core-populate-prefix"
  "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-subbuild/core-populate-prefix/tmp"
  "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-subbuild/core-populate-prefix/src/core-populate-stamp"
  "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-subbuild/core-populate-prefix/src"
  "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-subbuild/core-populate-prefix/src/core-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-subbuild/core-populate-prefix/src/core-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/erabs/Drive Data/MY_STUFF/develop/app/build/_deps/core-subbuild/core-populate-prefix/src/core-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
