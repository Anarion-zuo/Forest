//
// Created by anarion on 6/23/19.
//

#include "cnstFormatException.h"

cnstFormatException::cnstFormatException(cgNode *node, size_t index, size_t size) : nodeException(node), _index(index), _size(size) {}

const char *cnstFormatException::what() const _GLIBCXX_USE_NOEXCEPT {
    std::string s1("Exception when constructing a matrix. At index "), s2(" dimension"), s3(". Dimension of the vectors constructing the matrix must equal each other.");
    return (s1 + std::to_string(_index) + s2 + std::to_string(_size) + s3).c_str();
}
