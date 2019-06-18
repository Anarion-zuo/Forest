//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_NODEEXCEPTION_H
#define CPPFOREST_NODEEXCEPTION_H

#include <stdexcept>
#include "../../cgNode/cgNode.h"


class nodeException : public std::exception {
protected:
    cgNode* _node;
public:
    nodeException(cgNode* node);
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_NODEEXCEPTION_H
