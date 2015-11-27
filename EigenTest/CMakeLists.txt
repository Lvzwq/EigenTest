cmake_minimum_required(VERSION 3.3)
project(EigenTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Point.cpp Point.h Shape.cpp Shape.h func.cpp func.h)
add_executable(EigenTest ${SOURCE_FILES})