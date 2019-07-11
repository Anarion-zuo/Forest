//
// Created by anarion on 7/11/19.
//

#ifndef CPPFOREST_SINGLEVARIABLEEXCEPTION_H
#define CPPFOREST_SINGLEVARIABLEEXCEPTION_H

#include <string>
#include <bits/exception.h>

class SingleVariableException : std::exception {
    std::string _info;
public:
    SingleVariableException(const std::string&& info);
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_SINGLEVARIABLEEXCEPTION_H
