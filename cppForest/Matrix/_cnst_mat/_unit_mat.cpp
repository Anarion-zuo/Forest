//
// Created by anarion on 2019/7/30.
//

#include "_unit_mat.h"

_unit_mat::_unit_mat(size_t height, size_t width) : _cnst_mat(height, width) {
    for (size_t i = 0; i < _size; ++i){
        if (i / _width == i % _width){
            _mat[i] = 1;
        } else {
            _mat[i] = 0;
        }
    }
}
