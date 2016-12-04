cmake_minimum_required(VERSION 2.6)
project(etape1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp Machine.cpp)
add_executable(../test_fsa ${SOURCE_FILES})