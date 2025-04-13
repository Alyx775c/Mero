cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 23) # Update to the latest C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(glad
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gl.c
)

target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)