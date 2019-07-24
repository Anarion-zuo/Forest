//
// Created by anarion on 2019/7/19.
//

#ifndef CPPFOREST_CANNOTCONVERGEEXCEPTION_H
#define CPPFOREST_CANNOTCONVERGEEXCEPTION_H


#include <bits/exception.h>
#include <string>

class CannotConvergeException : std::exception {
protected:
    std::string _info;
public:
    explicit CannotConvergeException(const std::string&& info);
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_CANNOTCONVERGEEXCEPTION_H
