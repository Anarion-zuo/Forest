cmake_minimum_required(VERSION 3.14)
project(cForest)

set(CMAKE_CXX_STANDARD 14)

add_executable(cForest main.cpp common/_linked_list.cpp common/_linked_list.h GraphNode/Node.cpp GraphNode/Node.h)