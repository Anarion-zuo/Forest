# cmake_minimum_required(VERSION <specify CMake version here>)
project(cppForest)

set(CMAKE_CXX_STANDARD 17)

add_library(cppForest Forest.cpp library.h)