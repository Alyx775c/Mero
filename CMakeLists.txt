cmake_minimum_required(VERSION 3.10.0)
project(mero VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23) # Update to the latest C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(glad)
add_subdirectory(mero)
add_subdirectory(tests)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
