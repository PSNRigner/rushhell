#cmake_minimum_required(VERSION 3.6)
project(bind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp)
add_executable(../test_bind ${SOURCE_FILES})