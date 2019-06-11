//
// Created by anarion on 6/11/19.
//

#include "MatrixNode.h"

MatrixNode::MatrixNode(size_t height, size_t width) : _c(std::vector<std::vector<cgNode*>>(width, std::vector<cgNode*>(height, nullptr))) {}

size_t MatrixNode::height() {
    if (_c.empty()){
        return 0;
    }
    return _c[0].size();
}

size_t MatrixNode::width() {
    if (_c.empty()){
        return 0;
    }
    return _c.size();
}

cgNode *MatrixNode::loc(size_t i, size_t j) {
    if (i >= width() || j >= height()){
        return nullptr;
    }
    return _c[j][i];
}


