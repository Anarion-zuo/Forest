//
// Created by anarion on 19-5-31.
//

#include "Matrix.h"

Matrix::Matrix(size_t h, size_t w, double a) : _c(w, new Array(h, a)) {}

Matrix::Matrix(const std::vector<Array*> &c) : _c(c) {}

Matrix::~Matrix() {}

Matrix *Matrix::clone() {
    std::vector<Array*> v(_c.size(), nullptr);
    for (size_t i = 0; i < _c.size(); ++i){
        v[i] = _c[i]->clone();
    }
    return new Matrix(v);
}

size_t Matrix::width() {
    return _c.size();
}

size_t Matrix::height() {
    if (!_c.size()){
        return 0;
    }
    return _c[0]->size();
}

bool Matrix::empty() {
    return _c.empty();
}

Array *Matrix::sum() {
    Array* p = new Array(width(), 0);
    for (size_t i = 0; i < width(); ++i){
        (*p)[i] = _c[i]->sum();
    }
    return p;
}

Array *Matrix::prod() {
    Array* p = new Array(width(), 0);
    for (size_t i = 0; i < width(); ++i){
        (*p)[i] = _c[i]->prod();
    }
    return p;
}

Array *Matrix::mean() {
    Array* p = new Array(width(), 0);
    for (size_t i = 0; i < width(); ++i){
        (*p)[i] = _c[i]->mean();
    }
    return p;
}

Array *Matrix::moment(size_t n) {
    Array* p = new Array(width(), 0);
    for (size_t i = 0; i < width(); ++i){
        (*p)[i] = _c[i]->moment(n);
    }
    return p;
}

Array *Matrix::nth_item(size_t n) {
    Array* p = new Array(width(), 0);
    for (size_t i = 0; i < width(); ++i){
        (*p)[i] = _c[i]->nth_item(n);
    }
    return p;
}

Array *Matrix::most_frequent() {
    Array* p = new Array(width(), 0);
    for (size_t i = 0; i < width(); ++i){
        (*p)[i] = _c[i]->most_frequent();
    }
    return p;
}

double &Matrix::loc(size_t i, size_t j) {
    return (*_c[j])[i];
}

void Matrix::hstack(Matrix *m) {
    if (height() != m->height()){
        // exception
    }
    _c.insert(_c.end(), m->_c.begin(), m->_c.end());
}

void Matrix::vstack(Matrix *m) {
    if (width() != m->width()){
        // exceotion
    }
    for (size_t i = 0; i < width(); ++i){
        _c[i]->stack(m->_c[i]);
    }
}

Matrix *Matrix::partial(size_t i1, size_t j1, size_t i2, size_t j2) {
    auto p = new Matrix(i2 - i1, j2 - j1, 0);
    for (size_t i = i1; i < i2; ++i){
        for (size_t j = j1; j < j2; ++j){
            p->loc(i - i1, j - j1) = loc(i, j);
        }
    }
    return p;
}

Matrix *Matrix::transpose() {
    Matrix* p = new Matrix(width(), height(), 0);
    for (size_t i = 0; i < _c.size(); ++i){
        for (size_t j = 0; j < height(); ++j){
            p->loc(i, j) = loc(j, i);
        }
    }
    return p;
}

Matrix *Matrix::slow_mul(Matrix *m1, Matrix *m2) {
    if (m1->width() != m2->height()){
        // exception
    }
    auto p = new Matrix(m1->height(), m2->width(), 0);
    auto m11 = m1->transpose();
    for (size_t i = 0; i < p->height(); ++i){
        for (size_t j = 0; j < p->width(); ++j){
            Array* arr = Array::mul(m11->_c[i], m2->_c[j]);
            p->loc(i, j) = arr->sum();
            delete arr;
        }
    }
    return p;
}

Matrix *Matrix::add(Matrix *m1, Matrix *m2) {
    if (m1->width() != m2->width() || m1->height() != m2->height()){
        // exception
    }
    std::vector<Array*> c(m1->width(), nullptr);
    for (size_t i = 0; i < m1->_c.size(); ++i){
        c[i] = Array::add(m1->_c[i], m2->_c[i]);
    }
    return new Matrix(c);
}

Matrix *Matrix::sub(Matrix *m1, Matrix *m2) {
    if (m1->width() != m2->width() || m1->height() != m2->height()){
        // exception
    }
    std::vector<Array*> c(m1->width(), nullptr);
    for (size_t i = 0; i < m1->_c.size(); ++i){
        c[i] = Array::sub(m1->_c[i], m2->_c[i]);
    }
    return new Matrix(c);
}

Matrix *Matrix::mul(Matrix *m1, Matrix *m2) {
    return slow_mul(m1, m2);
}

#include <iostream>
std::string Matrix::to_string() {
    std::string str;
    for (size_t i = 0; i < height(); ++i){
        for (size_t j = 0; j < width(); ++j){
            str += std::to_string(loc(i, j));
            if (j == width() - 1){
                str += '\n';
            }else{
                str += ',';
            }
        }
    }
    return str;
}

void Matrix::_fill_0s(Matrix *m) {
    if (!m){
        return;
    }
    if (m->empty()){
        return;
    }

    if (m->height() > m->width()){
        size_t d = m->height() - m->width();
        auto tall = new Matrix(m->height(), d, 0);
        m->hstack(tall);
        delete tall;
    }else if (m->height() < m->width()){
        size_t d = m->width() - m->height();
        auto shor = new Matrix(d, m->width(), 0);
        m->hstack(shor);
        delete(shor);
    }
    if (m->height() % 2){
        m->_c.push_back(new Array(m->height(), 0));
        for (size_t i = 0; i < m->_c.size(); ++i){
            m->_c.push_back(0);
        }
    }
}

std::vector<Matrix *> *Matrix::_divide_four(Matrix *m) {
    if (!m){
        return new std::vector<Matrix*>;
    }
    if (m->empty()){
        return new std::vector<Matrix*>;
    }
    auto p = new std::vector<Matrix*>(4, nullptr);

    _fill_0s(m);

    size_t mid = m->height() / 2, full = m->height();
    (*p)[0] = m->partial(0, 0, mid, mid);
    (*p)[1] = m->partial(0, mid, mid, full);
    (*p)[2] = m->partial(mid, 0, full, mid);
    (*p)[3] = m->partial(mid, mid, full, full);

    return p;
}

Matrix *Matrix::_strassen_mul(Matrix *m1, Matrix *m2) {
    if (!m1 || !m2){
        return new Matrix(0,0,0);
    }
    if (m1->empty() || m2->empty()){
        return new Matrix(0,0,0);
    }
    if (m1->height() != m2->height() && m1->width() != m2->width()){
        throw "strassen error";
    }
    if (m1->width() <= 5 && m1->height() <= 5){
        slow_mul(m1, m2);
    }
    std::vector<Matrix*> * v1 = _divide_four(m1), * v2 = _divide_four(m2);

    //M1
    Matrix* at = add((*v1)[0], (*v2)[3]);
    Matrix* bt = add((*v2)[0], (*v2)[3]);
    Matrix* M1 = _strassen_mul(at, bt);
    delete at;
    delete bt;

    //M2
    at = add((*v1)[2], (*v2)[3]);
    Matrix* M2 = _strassen_mul(at, (*v2)[0]);
    delete at;

    //M3
    bt = sub((*v2)[1], (*v2)[3]);
    Matrix* M3 = _strassen_mul((*v1)[0], bt);
    delete bt;

    //M4
    bt = sub((*v2)[2], (*v2)[0]);
    Matrix* M4 = _strassen_mul((*v1)[3], bt);
    delete bt;

    //M5
    at = add((*v1)[0], (*v1)[1]);
    Matrix* M5 = _strassen_mul(at, (*v2)[3]);
    delete at;

    //M6
    at = sub((*v1)[2], (*v1)[0]);
    bt = add((*v2)[0], (*v2)[1]);
    Matrix* M6 = _strassen_mul(at, bt);
    delete at;
    delete bt;

    //M7
    at = sub((*v1)[1], (*v1)[3]);
    bt = add((*v2)[2], (*v2)[3]);
    Matrix* M7 = _strassen_mul(at, bt);
    delete at;
    delete bt;

    //C11
    at = add(M1, M4);
    bt = at;
    at = sub(at, M5);
    Matrix* C11 = add(at, M7);
    delete at;
    delete bt;

    //C12
    Matrix* C12 = add(M3, M5);

    //C21
    Matrix* C21 = add(M2, M4);

    //C22
    at = sub(M1, M2);
    bt = at;
    at = add(at, M3);
    Matrix* C22 = add(at, M6);
    delete at;
    delete bt;

    C11->hstack(C12);
    C21->hstack(C22);
    C11->vstack(C21);

    delete C12;
    delete C21;
    delete C22;
    delete M1;
    delete M2;
    delete M3;
    delete M4;
    delete M5;
    delete M6;
    delete M7;

    return C11;
}




