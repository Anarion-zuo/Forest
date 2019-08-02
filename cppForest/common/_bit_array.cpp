//
// Created by anarion on 2019/8/2.
//

#include "_bit_array.h"

_bit_array::_bit_array(size_t size) : _size(size / 64 + 1), _ptr(new long[_size]) {

}

_bit_array::~_bit_array() {
    delete []_ptr;
}

void _bit_array::set_bit(size_t index) {
    size_t i = index / 64, j = index % 64;
    long tmp = 1 << j;
    _ptr[i] |= tmp;
}

bool _bit_array::get_bit(size_t index) {
    size_t i = index / 64, j = index % 64;
    long t = _ptr[i];
    long tt = 1 << j;
    return t & tt;
}

void _bit_array::clear_bit(size_t index) {
    size_t i = index / 64, j = index % 64;
    long t = 1 << j;
    t = ~t;
    _ptr[i] &= t;
}

void _bit_array::set_all() {
    for (size_t i = 0; i < _size; ++i){
        _ptr[i] = 0xffffffffffffffff;
    }
}

void _bit_array::clear_all() {
    for (size_t i = 0; i < _size; ++i){
        _ptr[i] = 0x0;
    }
}

void _bit_array::resize(size_t size) {
    size /= 64;
    size += 1;
    auto p = new long[size];
    if (_size < size){
        size = _size;
    }
    for (size_t i = 0; i < size; ++i){
        p[i] = _ptr[i];
    }
    delete []_ptr;
    _ptr = p;
}
