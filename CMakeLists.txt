cmake_minimum_required (VERSION 3.10)
project (3D_Maze)

set(CMAKE_BUILD_TYPE Release)

add_subdirectory(tests)
add_executable(pathFinder pathFinder.h main.cpp)

