#cmake_minimum_required(VERSION 3.6)
project(etape4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES Edge.cpp State.cpp FSA.cpp Matcher.cpp main.cpp)
add_executable(../test_nsa_to_dfa ${SOURCE_FILES})