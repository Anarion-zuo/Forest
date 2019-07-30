//
// Created by anarion on 2019/7/29.
//

#include "_cnst_mat.h"
#include "../MyException/NumericMatrixException/MatrixShapeException.h"
#include "_unit_mat.h"
#include "_cnst_vec.h"

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

void _cnst_mat::_eliminate(_cnst_mat* in, size_t rowi, size_t coli) {
    size_t i = 0, j, rowp = rowi * in->_width;
    double piv = in->_mat[coli + rowp];
    for (; i < in->_height; ++i){
        if (i == rowi){
            continue;
        }
        j = 0;
        size_t rowd = i * in->_width;
        double q = in->_mat[coli + rowd] / piv;

        for (; j < in->_width; ++j){
            in->_mat[j + rowd] -= q * in->_mat[j + rowp];
        }
    }
}

void _cnst_mat::_eliminate_with(_cnst_mat *in, _cnst_mat *perm, _cnst_mat *b, size_t rowi, size_t coli) {
    size_t i = 0, j, rowp = rowi * in->_width;
    double piv = in->_mat[coli + rowp];
    for (; i < in->_height; ++i){
        if (i == rowi){
            continue;
        }
        j = 0;
        size_t rowd = i * in->_width;
        double q = in->_mat[coli + rowd] / piv;

        for (; j < in->_width; ++j){
            size_t pos1 = j + rowp;
            double res = q * in->_mat[pos1];
            size_t pos = j + rowd;
            in->_mat[pos] -= res;
            if (perm){
                res = q * perm->_mat[pos1];
                perm->_mat[pos] -= res;
            }
            if (b) {
                res = q * b->_mat[pos1];
                b->_mat[pos] -= res;
            }
        }
    }
}

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

size_t _cnst_mat::get_width() {
    return _width;
}

size_t _cnst_mat::get_height() {
    return _height;
}

void _cnst_mat::_LU_fact(_cnst_mat *in, _cnst_mat *b, _cnst_mat **lo, _cnst_mat **uo, _cnst_mat** newb, size_t **order) {
    in = in->clone();
    b = b->clone();
    size_t height = in->_height, width = in->_width;
    auto stack = new size_t[width];
    double *mat = in->_mat;
//    size_t len;
//    if (in->_width >= in->_height){
//        len = in->_height;
//    } else {
//        len = in->_width;
//    }
    auto unit = new _unit_mat(height, width);
    for (size_t i = 0; i < width; ++i){
        size_t ri = _largest_row(in, 0, i);
        stack[i] = ri;
        _eliminate_with(in, unit, b, ri, i);
    }
    *lo = unit;
    *uo = in;
    *order = stack;
    *newb = b;
}

size_t _cnst_mat::_largest_row(_cnst_mat *in, size_t rowi, size_t coli) {
    size_t res = 0;
    double *mat = in->_mat;
    double piv = mat[coli];
    for (size_t i = rowi; i < in->_height; ++i){
        size_t loc = coli + in->_width * i;
        double temp = mat[loc];
        if (temp > piv){
            piv = temp;
            res = i;
        }
    }
    return res;
}

void _cnst_mat::_solve_lcpb(_cnst_mat *lm, _cnst_mat *newb, size_t *order, _cnst_mat **c) {
    size_t width = lm->_width;
    auto mat = new double[width];
    for (size_t i = width - 1; i <= width; --i){
        size_t o = order[i];
        for (size_t j = i; j < width; ++j){

        }
    }
    *c = new _cnst_mat(mat, width, 1);
}

