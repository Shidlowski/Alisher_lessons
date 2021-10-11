cmake_minimum_required(VERSION 3.17)
project(istorage)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(include/storagelib)
add_subdirectory(test)