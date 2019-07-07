//
// Created by anarion on 7/6/19.
//

#include "nullException.h"

nullException::nullException(cgNode *node, const std::string &&info) : nodeException(node), _info(info) {}

const char *nullException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _info.c_str();
}
