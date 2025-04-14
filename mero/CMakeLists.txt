cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 20) # Update to the latest C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES *.cpp)

add_library(mero_lib
    ${SRC_FILES}
)

target_include_directories(mero_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    glad
)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

target_link_libraries(mero_lib
    glfw
    vulkan
)

set_target_properties(mero_lib PROPERTIES EXPORT_NAME MeroLib)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    enable_testing()
endif()