//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST_GETNONCONSTVALEXCEPTION_H
#define CPPFOREST_GETNONCONSTVALEXCEPTION_H


#include "../nodeException.h"

class getnonconstValException : public nodeException {
public:
    explicit getnonconstValException(cgNode* node);  // takes the parent
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_GETNONCONSTVALEXCEPTION_H
