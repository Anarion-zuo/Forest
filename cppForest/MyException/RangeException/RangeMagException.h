//
// Created by anarion on 7/8/19.
//

#ifndef CPPFOREST_RANGEMAGEXCEPTION_H
#define CPPFOREST_RANGEMAGEXCEPTION_H

#include <string>
#include <bits/exception.h>

class RangeMagException : public std::exception {
    double _left, _right;
    std::string _info;
public:
    explicit RangeMagException(double left, double right);  // takes the parent
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_RANGEMAGEXCEPTION_H
