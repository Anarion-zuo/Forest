//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_MATRIXNODE_H
#define CPPFOREST_MATRIXNODE_H


#include "../cgNode.h"

class MatrixNode {
protected:
    std::vector<std::vector<cgNode*>> _c;
public:
    MatrixNode(size_t height, size_t width);

    size_t height();
    size_t width();
    cgNode* loc(size_t i, size_t j);
};


#endif //CPPFOREST_MATRIXNODE_H
