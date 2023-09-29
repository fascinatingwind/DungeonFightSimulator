cmake_minimum_required(VERSION 3.16)
project(Simulator)
include_directories(include)
link_directories(src)

set(HEADER_FILES
	"include/main.h"
)
set(SOURCE_FILES
	"src/main.cpp"
	)

add_executable(Simulator ${HEADER_FILES} ${SOURCE_FILES})