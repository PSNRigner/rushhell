#cmake_minimum_required(VERSION 3.6)
project(etape2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp)
add_executable(../test_function ${SOURCE_FILES})