cmake_minimum_required(VERSION 3.16)

project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL "https://github.com/google/googletest/archive/refs/heads/main.zip"
)

FetchContent_MakeAvailable(googletest)

# Main executable
add_executable(lab1 main.cpp math_operations.cpp)

# Tests
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")

if(TEST_SOURCES)
    enable_testing()
    add_executable(unit_tests ${TEST_SOURCES} math_operations.cpp)
    target_link_libraries(unit_tests PRIVATE GTest::gtest_main)
    target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    include(GoogleTest)
    gtest_discover_tests(unit_tests)
endif()
