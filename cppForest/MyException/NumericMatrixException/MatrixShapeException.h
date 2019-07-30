//
// Created by anarion on 2019/7/29.
//

#ifndef CPPFOREST_MATRIXSHAPEEXCEPTION_H
#define CPPFOREST_MATRIXSHAPEEXCEPTION_H

#include <string>
#include <exception>

class MatrixShapeException : public std::exception {
protected:
    size_t _h1, _h2, _w1, _w2;
public:
    MatrixShapeException(size_t h1, size_t w1, size_t h2, size_t w2);
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override ;
};


#endif //CPPFOREST_MATRIXSHAPEEXCEPTION_H
