include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

file(GLOB_RECURSE TEST_SOURCES *.cpp)

add_executable(mero_tests ${TEST_SOURCES})

target_include_directories(mero_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/Mero/inc
)

target_link_libraries(mero_tests
    PRIVATE
        Mero 
        Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(mero_tests)
