cmake_minimum_required(VERSION 3.16)
project(Simulator)
include_directories(include)
link_directories(src)

set(HEADER_FILES
	"include/main.h"
	"include/character.h"
	"include/dice.h"
	"include/action.h"
	"include/makefooaction.h"
	"include/filehandling.h"
	"include/parser.h"
	)

set(SOURCE_FILES
	"src/main.cpp"
	"src/action.cpp"
	"src/dice.cpp"
	"src/character.cpp"
	"src/filehandling.cpp"
	"src/parser.cpp"
	)

add_executable(Simulator ${HEADER_FILES} ${SOURCE_FILES})
