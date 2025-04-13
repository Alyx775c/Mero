cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 23) # Update to the latest C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(mero_lib
    ${SRC_FILES}
)

target_include_directories(mero_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    glfw/include
)

# Correctly find and link SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_link_libraries(mero_lib
    SDL2::SDL2
    SDL2_image::SDL2_image
    glfw
)

set_target_properties(mero_lib PROPERTIES EXPORT_NAME MeroLib)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    enable_testing()
endif()