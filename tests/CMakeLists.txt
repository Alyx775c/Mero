# Fetch Catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

# Add test executable
file(GLOB_RECURSE TEST_SOURCES *.cpp)

add_executable(mero_tests
  ${TEST_SOURCES}
)

# Include your library headers
target_include_directories(mero_tests PRIVATE
  ${CMAKE_SOURCE_DIR}/Mero/inc
)

# Link your actual library and Catch2
target_link_libraries(mero_tests
  PRIVATE
    mero        # <-- this is the target from Mero/CMakeLists.txt
    Catch2::Catch2WithMain
)

# Enable test discovery
include(CTest)
include(Catch)
catch_discover_tests(mero_tests)
