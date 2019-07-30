//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_VECTYPEEXCEPTION_H
#define CPPFOREST_VECTYPEEXCEPTION_H


#include "../nodeException.h"

class vecTypeException : public nodeException {
protected:
    size_t _index;
public:
    explicit vecTypeException(_cg_node* node, size_t index);  // takes the parent
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_VECTYPEEXCEPTION_H
