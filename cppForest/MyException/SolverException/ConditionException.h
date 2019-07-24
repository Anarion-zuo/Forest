//
// Created by anarion on 2019/7/18.
//

#ifndef CPPFOREST_CONDITIONEXCEPTION_H
#define CPPFOREST_CONDITIONEXCEPTION_H


#include <bits/exception.h>
#include <string>

class ConditionException : public std::exception {
protected:
    std::string _info;
public:
    ConditionException(const std::string&& info);
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_CONDITIONEXCEPTION_H
