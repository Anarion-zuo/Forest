//
// Created by anarion on 6/18/19.
//

#include "vecTypeException.h"

vecTypeException::vecTypeException(cgNode *node, size_t index) : nodeException(node), _index(index) {}

const char *vecTypeException::what() const _GLIBCXX_USE_NOEXCEPT {
    std::string info1("Component "), info2(" has multiple components.");
    return (info1 + std::to_string(_index) + info2).c_str();
}
