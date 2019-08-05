//
// Created by anarion on 2019/8/5.
//

#include "_matrix.h"

_matrix::_matrix(size_t height, size_t width) : _height(height), _width(width) {

}

_matrix::_matrix() : _width(0), _height(0) {

}

size_t _matrix::get_width() {
    return _width;
}

size_t _matrix::get_height() {
    return _height;
}