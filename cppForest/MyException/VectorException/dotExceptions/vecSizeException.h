//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_VECSIZEEXCEPTION_H
#define CPPFOREST_VECSIZEEXCEPTION_H


#include "../../../cgNode/cgNode.h"
#include "../nodeException.h"

class vecSizeException : public nodeException {
public:
    explicit vecSizeException(cgNode* node);
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_VECSIZEEXCEPTION_H
