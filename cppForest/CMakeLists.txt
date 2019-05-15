cmake_minimum_required(VERSION 3.14)
project(cppForest)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppForest main.cpp ./cgNode/cgNode.cpp Garbage_Bin.cpp Garbage_Bin.h cgNode/addNode.cpp cgNode/addNode.h cgNode/mulNode.cpp cgNode/mulNode.h cgNode/divNode.cpp cgNode/divNode.h cgNode/subNode.cpp cgNode/subNode.h cgNode/constNode.cpp cgNode/constNode.h cgNode/varNode.cpp cgNode/varNode.h cg/cg.cpp cg/cg.h cgNode/expNode.cpp cgNode/expNode.h cgNode/monopNodes/lnNode.cpp cgNode/monopNodes/lnNode.h cgNode/monopNodes/monopNode.cpp cgNode/monopNodes/monopNode.h cgNode/monopNodes/sinNode.cpp cgNode/monopNodes/sinNode.h)
