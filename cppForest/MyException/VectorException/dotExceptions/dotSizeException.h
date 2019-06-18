//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_DOTSIZEEXCEPTION_H
#define CPPFOREST_DOTSIZEEXCEPTION_H


#include "../../../cgNode/cgNode.h"
#include "../nodeException.h"

class dotSizeException : public nodeException {
public:
    explicit dotSizeException(cgNode* node);
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_DOTSIZEEXCEPTION_H
