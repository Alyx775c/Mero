# tests/CMakeLists.txt

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

# Gather test sources
file(GLOB_RECURSE TEST_SOURCES *.cpp)

add_executable(mero_tests ${TEST_SOURCES})

# Add include dirs if needed (optional if headers are public via mero_lib)
target_include_directories(mero_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/Mero/inc
)

# Link with the actual library and Catch2
target_link_libraries(mero_tests
    PRIVATE
        mero_lib
        Catch2::Catch2WithMain
)

# Auto-discover tests with CTest
include(CTest)
include(Catch)
catch_discover_tests(mero_tests)
