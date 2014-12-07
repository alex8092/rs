cmake_minimum_required(VERSION 2.8)

project(rs)

SET(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

SET(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(
	include/
)

file(
	GLOB_RECURSE
	source_files
	src/*
)

file(
	GLOB_RECURSE
	header_files
	include/*
)

add_executable(
	rs
	${header_files}
	${source_files}
)