//
// Created by anarion on 7/6/19.
//

#include "nullException.h"

nullException::nullException(const std::string &&info) : _info(info) {}

const char *nullException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _info.c_str();
}
