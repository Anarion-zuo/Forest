//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_SINGLEEXCEPTION_H
#define CPPFOREST_SINGLEEXCEPTION_H


#include "../nodeException.h"

class singleException : public nodeException {
public:
    explicit singleException(_cg_node* node);
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_SINGLEEXCEPTION_H
