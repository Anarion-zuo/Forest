//
// Created by anarion on 7/11/19.
//

#include "SingleVariableException.h"

SingleVariableException::SingleVariableException(const std::string &&info) : _info(info){}

const char *SingleVariableException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _info.c_str();
}
