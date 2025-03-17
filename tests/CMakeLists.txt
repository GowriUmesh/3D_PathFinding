cmake_minimum_required (VERSION 3.10)
project (PATHFINDER_TESTS)

set(CMAKE_BUILD_TYPE Release)

find_package(GTest REQUIRED)

add_executable(run_pathFinder_tests ../pathFinder.h pathFinder_tests.cpp)
target_link_libraries(run_pathFinder_tests GTest::GTest GTest::Main)

enable_testing()
add_test(NAME PATHFINDER_TESTS COMMAND run_pathFinder_tests)
