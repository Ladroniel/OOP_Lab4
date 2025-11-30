cmake_minimum_required(VERSION 3.10)
project(LR4_Figures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(lr4 src/main.cpp)


enable_testing()
add_subdirectory(tests)
