cmake_minimum_required(VERSION 3.5)

project(List)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gtest gtest.cpp)
target_link_libraries(gtest ${GTEST_LIBRARIES} pthread)

add_executable(test.out test.cpp)