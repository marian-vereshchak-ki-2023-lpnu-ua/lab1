cmake_minimum_required(VERSION 3.10)

project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab1 main.cpp)

add_library(math_operations math_operations.cpp)
target_include_directories(math_operations
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(lab1 PRIVATE math_operations)

find_package(GTest REQUIRED)

enable_testing()

add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE math_operations GTest::gtest_main)

add_test(NAME unit_tests COMMAND unit_tests)
