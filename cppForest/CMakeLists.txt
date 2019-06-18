cmake_minimum_required(VERSION 3.14)
project(cppForest)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppForest main.cpp  cgNode/cgNode.cpp cgNode/cgNode.h cgNode/singleNodes/singleNode.cpp cgNode/singleNodes/singleNode.h cgNode/multiop/sumNode.cpp cgNode/multiop/sumNode.h cgNode/vectorOp/dotNode.cpp cgNode/vectorOp/dotNode.h MyException/VectorException/nodeException.cpp MyException/VectorException/nodeException.h MyException/VectorException/dotExceptions/dotSizeException.cpp MyException/VectorException/dotExceptions/dotSizeException.h MyException/VectorException/dotExceptions/dotTypeException.cpp MyException/VectorException/dotExceptions/dotTypeException.h cgNode/singleNodes/number/constNode.cpp cgNode/singleNodes/number/constNode.h cgNode/singleNodes/number/varNode.cpp cgNode/singleNodes/number/varNode.h cgNode/var.cpp cgNode/vecNode.cpp cgNode/vecNode.h cgNode/singleNodes/op/lnNode.cpp cgNode/singleNodes/op/lnNode.h cgNode/singleNodes/op/powNode.cpp cgNode/singleNodes/op/powNode.h MyException/VectorException/singleException/singleException.cpp MyException/VectorException/singleException/singleException.h)
