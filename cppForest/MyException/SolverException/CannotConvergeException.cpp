//
// Created by anarion on 2019/7/19.
//

#include "CannotConvergeException.h"

CannotConvergeException::CannotConvergeException(const std::string &&info) : _info(info) {}

const char *CannotConvergeException::what() const _GLIBCXX_USE_NOEXCEPT {
    std::string s1("Convergence Exception: ");
    return (s1 + _info).c_str();
}
