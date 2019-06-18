//
// Created by anarion on 6/18/19.
//

#include "nodeException.h"

const char *nodeException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT{
    return "Exception occurred in a Node.";
}

nodeException::nodeException(cgNode *node) : _node(node) {}
