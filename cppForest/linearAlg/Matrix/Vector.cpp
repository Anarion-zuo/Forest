//
// Created by anarion on 6/9/19.
//

#include "Vector.h"

Vector::Vector(size_t size, double n) : Matrix(size, 1, n) {}

Vector::Vector(std::vector<double> &list) : Matrix(std::vector<Array*>(1, new Array(list))) {}
