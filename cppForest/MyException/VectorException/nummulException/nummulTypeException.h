//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST_NUMMULTYPEEXCEPTION_H
#define CPPFOREST_NUMMULTYPEEXCEPTION_H


#include "../nodeException.h"

class nummulTypeException : public nodeException {
protected:
public:
    explicit nummulTypeException(_cg_node* node);  // takes the parent
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_NUMMULTYPEEXCEPTION_H
