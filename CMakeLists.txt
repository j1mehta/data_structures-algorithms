cmake_minimum_required(VERSION 3.6)
project(ValidAnagram)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ValidAnagram.cpp)
add_executable(ValidAnagram ${SOURCE_FILES})