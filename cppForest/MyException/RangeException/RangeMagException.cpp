//
// Created by anarion on 7/8/19.
//

#include "RangeMagException.h"

RangeMagException::RangeMagException(double left, double right) : _left(left), _right(right) {
    std::string s1("Range lower bound "), s2(" larger than upper bound ");
    std::string ret = s1 + std::to_string(left) + s2 + std::to_string(right) + std::string(".");
    _info = std::move(ret);
}

const char *RangeMagException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _info.c_str();
}
