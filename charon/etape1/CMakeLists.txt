#cmake_minimum_required(VERSION 3.6)
project(etape1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp)
add_executable(../test_functor_type ${SOURCE_FILES})