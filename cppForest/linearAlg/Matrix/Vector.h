//
// Created by anarion on 6/9/19.
//

#ifndef CPPFOREST_VECTOR_H
#define CPPFOREST_VECTOR_H

#include "Matrix.h"

class Vector : public Matrix {
public:
    Vector(size_t size, double n);
    Vector(std::vector<double>& list);
};


#endif //CPPFOREST_VECTOR_H
