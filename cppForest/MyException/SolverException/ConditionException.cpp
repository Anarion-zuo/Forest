//
// Created by anarion on 2019/7/18.
//

#include "ConditionException.h"

ConditionException::ConditionException(const std::string &&info) : _info(info) {}

const char *ConditionException::what() const _GLIBCXX_USE_NOEXCEPT {
    std::string ret("The solver got input condition contradicts to the current state of the function and property of the solver: ");
    ret += _info;
    return ret.c_str();
}
