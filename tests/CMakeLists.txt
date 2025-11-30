cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(run_tests test_figures.cpp)

target_link_libraries(run_tests
    GTest::GTest
    GTest::Main
    pthread
)
