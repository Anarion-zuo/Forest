//
// Created by anarion on 6/18/19.
//

#include "singleException.h"

singleException::singleException(cgNode *node) : nodeException(node) {}

const char *singleException::what() const _GLIBCXX_USE_NOEXCEPT {
    return "The attribute _result should be a single value, not a multi-dimensional vector.";
}
