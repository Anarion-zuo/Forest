//
// Created by anarion on 6/18/19.
//

#include "singleException.h"

singleException::singleException(cgNode *node) : nodeException(node) {}

const char *singleException::what() const _GLIBCXX_USE_NOEXCEPT {
    return "Expect a vector node with a single component.";
}
