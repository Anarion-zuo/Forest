//
// Created by anarion on 7/6/19.
//

#ifndef CPPFOREST_NULLEXCEPTION_H
#define CPPFOREST_NULLEXCEPTION_H


#include "VectorException/nodeException.h"

class nullException : public std::exception {
    std::string _info;
public:
    explicit nullException(const std::string&& info);  // takes the parent
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_NULLEXCEPTION_H
