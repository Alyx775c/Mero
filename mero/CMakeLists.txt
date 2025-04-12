cmake_minimum_required(VERSION 3.10.0)

add_library(mero_lib
    src/mero.cpp 
)

target_include_directories(mero_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_include_directories(mero_lib PUBLIC
    glfw/include
)

target_link_libraries(mero_lib glfw)

set_target_properties(mero_lib PROPERTIES EXPORT_NAME MeroLib)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    enable_testing()
endif()