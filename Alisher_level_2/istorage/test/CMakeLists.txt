project(tests_storagelib)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

include_directories(
        ${GTEST_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_executable(tests main.cpp storage.test.cpp)

target_link_libraries(tests PRIVATE storagelib gtest Threads::Threads)
