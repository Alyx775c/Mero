cmake_minimum_required(VERSION 3.10.0)
project(mero VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()

add_subdirectory(mero)
add_subdirectory(tests)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
