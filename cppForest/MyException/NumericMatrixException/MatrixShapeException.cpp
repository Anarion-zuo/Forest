//
// Created by anarion on 2019/7/29.
//

#include "MatrixShapeException.h"
#include "../../Matrix/_cnst_mat.h"

const char *MatrixShapeException::what() const _GLIBCXX_USE_NOEXCEPT {
    std::string str("Operating on 2 matrix with shapes not matching each other. ");
    std::string s2("Got shape: "), s3(", "), s4("×");
    return (str + s2 + std::to_string(_h1) + s4 + std::to_string(_w1) + s3 + std::to_string(_h2) + s4 + std::to_string(_w2)).c_str();
}

MatrixShapeException::MatrixShapeException(size_t h1, size_t w1, size_t h2, size_t w2) : _h1(h1), _h2(h2), _w1(w1), _w2(w2){}
