project(tests)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

include_directories(${GTEST_INCLUDE_DIR})

add_executable(tests main.cpp variable2.cpp)

target_link_libraries(tests Variable_lib gtest Threads::Threads)
