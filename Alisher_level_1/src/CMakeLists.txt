project(Variable_lib)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        )

file(GLOB HDRS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        )

add_library(${PROJECT_NAME} STATIC  ${HDRS} ${SRCS})