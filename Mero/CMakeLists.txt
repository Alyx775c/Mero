cmake_minimum_required(VERSION 3.10.0)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(Mero
    ${SRC_FILES}
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

target_include_directories(Mero PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_SOURCE_DIR}/glad/include
)

target_link_libraries(Mero
    OpenGL
    glfw
    glad
    dl
    pthread
    X11
    Xxf86vm
    Xrandr
    Xi
)

set_target_properties(Mero PROPERTIES EXPORT_NAME MeroLib)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    enable_testing()
endif()