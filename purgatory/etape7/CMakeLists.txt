cmake_minimum_required(VERSION 2.6)
project(etape7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES Edge.cpp State.cpp FSA.cpp Matcher.cpp ExpressionParser.cpp main.cpp)
add_executable(../test_notifier ${SOURCE_FILES})