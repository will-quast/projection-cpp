cmake_minimum_required(VERSION 3.6)
project(calories)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES library.cpp library.h main.cpp main.h)
add_executable(calories ${SOURCE_FILES})