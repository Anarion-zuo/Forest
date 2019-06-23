//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST_CNSTFORMATEXCEPTION_H
#define CPPFOREST_CNSTFORMATEXCEPTION_H


#include "../../VectorException/nodeException.h"

class cnstFormatException : nodeException {
private:
    size_t _size;
    size_t _index;
public:
    explicit cnstFormatException(cgNode* node, size_t index, size_t size);
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_CNSTFORMATEXCEPTION_H
