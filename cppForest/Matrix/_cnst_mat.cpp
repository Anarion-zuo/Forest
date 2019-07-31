//
// Created by anarion on 2019/7/29.
//

#include "_cnst_mat.h"
#include "../MyException/NumericMatrixException/MatrixShapeException.h"
#include "_unit_mat.h"
#include "_cnst_vec.h"
extern "C"{
    #include "_gaussian_elimination.h"
}

_cnst_mat::_cnst_mat(size_t height, size_t width) : _mat(new double[height * width]), _width(width), _height(height), _size(height * width){}

_cnst_mat::_cnst_mat() : _mat(nullptr), _width(0), _height(0), _size(0) {}

_cnst_mat::~_cnst_mat() {
    delete[] _mat;
}

_cnst_mat::_cnst_mat(double n, size_t height, size_t width) : _mat(new double[height * width]), _width(width), _height(height), _size(height * width) {
    for (size_t i = 0; i < _size; ++i){
        _mat[i] = n;
    }
}

double &_cnst_mat::loc(size_t i, size_t j) {
    size_t location = i * _width + j;
    return _mat[location];
}

_cnst_mat *_cnst_mat::clone() {
    auto *newmat = new double[_size];
    for (size_t i = 0; i < _size; ++i){
        newmat[i] = _mat[i];
    }
    return new _cnst_mat(newmat, _height, _width);
}

_cnst_mat::_cnst_mat(double *mat, size_t height, size_t width) : _mat(mat), _width(width), _height(height), _size(height * width) {}

std::string _cnst_mat::to_string() {
    std::string ret;
    for (size_t i = 0; i < _size; ++i){
        ret += std::to_string(_mat[i]) + ',';
        if ((i + 1) % _width == 0){
            ret += '\n';
        }
    }
    return ret;
}

void _cnst_mat::negative(_cnst_mat *m) {
    double *mat = m->_mat;
    size_t len = m->_size;
    for (size_t i = 0; i < len; ++i){
        double t = mat[i];
        mat[i] = -t;
    }
}

_cnst_mat *_cnst_mat::add(_cnst_mat *ma, _cnst_mat *mb) {
    if (ma->_width != mb->_width || ma->_height != mb->_height){
        throw MatrixShapeException(ma->_height, ma->_width, mb->_height, mb->_width);
    }
    size_t len = ma->_size;
    double *m1 = ma->_mat, *m2 = mb->_mat, *mat = new double[len];
    for (size_t i = 0; i < len; ++i){
        mat[i] = m1[i] + m2[i];
    }
    return new _cnst_mat(mat, ma->_height, ma->_width);
}

_cnst_mat *_cnst_mat::sub(_cnst_mat *ma, _cnst_mat *mb) {
    if (ma->_width != mb->_width || ma->_height != mb->_height){
        throw MatrixShapeException(ma->_height, ma->_width, mb->_height, mb->_width);
    }
    size_t len = ma->_size;
    double *m1 = ma->_mat, *m2 = mb->_mat, *mat = new double[len];
    for (size_t i = 0; i < len; ++i){
        mat[i] = m1[i] - m2[i];
    }
    return new _cnst_mat(mat, ma->_height, ma->_width);
}

_cnst_mat *_cnst_mat::_naive_mul(_cnst_mat *ma, _cnst_mat *mb) {
    if (ma->_width != mb->_height){
        throw MatrixShapeException(ma->_height, ma->_width, mb->_height, mb->_width);
    }

}

void _cnst_mat::times_const(double n) {
    size_t len = _size;
    double *pbegin = _mat, *pend = pbegin + len;
    for (; pbegin != pend; ++pbegin){
        *pbegin *= n;
    }
}

void _cnst_mat::scale_row(size_t index, double n) {
    size_t len = _size;
    double *pbegin = _mat + _width * index, *pend = pbegin + _width;
    for (; pbegin != pend; ++pbegin){
        *pbegin *= n;
    }
}

void _cnst_mat::scale_col(size_t index, double n) {
    size_t len = _size;
    double *pbegin = _mat + index, *pend = pbegin + _size;
    for (; pbegin != pend; pbegin += _width){
        *pbegin *= n;
    }
}

void _cnst_mat::plus_row(size_t srow, size_t drow) {
    double *mat = _mat;
    size_t width = _width;
    double *b1 = mat + width * srow, *b2 = mat + width * drow, *e1 = b1 + width - 1;
    for (; b1 != e1; ++b1, ++b2){
        *b2 += *b1;
    }
}



size_t _cnst_mat::get_width() {
    return _width;
}

size_t _cnst_mat::get_height() {
    return _height;
}



void _cnst_mat::reshape(size_t height, size_t width) {
    _height = height;
    _width = width;
}

_cnst_mat *_cnst_mat::arrange(double begin, double end, double step) {
    size_t len = (end - begin) / step;
    auto arr = new double[len];
    for (size_t i = 0; i < len; ++i){
        arr[i] = begin;
        begin += step;
    }
    return new _cnst_mat(arr, len, 1);
}

_cnst_mat::_cnst_mat(std::vector<std::vector<double>> &&vec) : _height(vec.size()), _width(vec[0].size()) {
    _size = _width * _height;
    _mat = new double[_size];
    size_t i = 0;
    for (auto& row : vec){
        for (auto col : row){
            _mat[i] = col;
            ++i;
        }
    }
}

std::vector<_cnst_mat *> _cnst_mat::_perfect_cond(_cnst_mat *input, const std::vector<_cnst_mat *>& rhs) {
    size_t bnum = rhs.size(), width = input->_width, height = input->_height;
    double *amat = input->_mat, **bmat = new double*[width], ***ans;
    for (size_t i = 0; i < bnum; ++i){
        bmat[i] = rhs[i]->_mat;
    }
    _perfect_cond_int(amat, bmat, bnum, ans, width, height);
    double **an = *ans;
    std::vector<_cnst_mat*> vec(bnum);
    for (size_t i = 0; i < bnum; ++i){
        vec[i] = new _cnst_mat(an[i], height, 1);
    }
    return std::move(vec);
}


