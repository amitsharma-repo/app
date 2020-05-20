cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUID_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++14")

project(feature_app)

add_executable(
	feature_app
	feature_app.cpp
	)	
