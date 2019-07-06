//
// Created by anarion on 7/6/19.
//

#ifndef CPPFOREST_NULLEXCEPTION_H
#define CPPFOREST_NULLEXCEPTION_H


#include "nodeException.h"

class nullException : public nodeException {
    std::string _info;
public:
    explicit nullException(cgNode* node, const std::string&& info);  // takes the parent
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_NULLEXCEPTION_H
