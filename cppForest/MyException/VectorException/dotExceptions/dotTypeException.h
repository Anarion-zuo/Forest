//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_DOTTYPEEXCEPTION_H
#define CPPFOREST_DOTTYPEEXCEPTION_H


#include "../nodeException.h"

class dotTypeException : public nodeException {
protected:
    size_t _index;
public:
    explicit dotTypeException(cgNode* node, size_t index);  // takes the parent
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_DOTTYPEEXCEPTION_H
