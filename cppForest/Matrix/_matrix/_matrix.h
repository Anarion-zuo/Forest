//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST__MATRIX_H
#define CPPFOREST__MATRIX_H

#include <string>
#include <cstdio>

class _matrix {
protected:
    size_t _width, _height;
public:
    _matrix();
    _matrix(size_t height, size_t width);
    virtual ~_matrix() = default;

    size_t get_width();
    size_t get_height();

    virtual _matrix* clone() = 0;

    virtual void reshape(size_t height, size_t width) = 0;

    // serialize
    virtual std::string to_string() = 0;

    // access matrix
    virtual double& loc(size_t i, size_t j) = 0;

};


#endif //CPPFOREST__MATRIX_H
