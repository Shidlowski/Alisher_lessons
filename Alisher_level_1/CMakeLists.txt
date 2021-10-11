cmake_minimum_required(VERSION 3.17)
project(Alisher_level_1)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(test)