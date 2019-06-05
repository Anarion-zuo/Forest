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
    return _c[0]->size();
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
    auto p = new Matrix(i2 - i1 + 1, j2 - j1 + 1, 0);
    for (size_t i = i1; i <= i2; ++i){
        for (size_t j = j1; j <= j2; ++j){
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

/*
 *  A0  A1
 *  A2  A3
 * */

std::vector<Matrix *> *Matrix::_divide_four(Matrix *m) {
    size_t mid = m->height() / 2 - 1;
    auto p = new std::vector<Matrix*>(4, nullptr);
    (*p)[0] = m->partial(0, 0, mid, mid);
    (*p)[1] = m->partial(0, mid + 1, mid + 1, m->width() - 1);
    (*p)[2] = m->partial(mid + 1, 0, m->width() - 1, mid);
    (*p)[3] = m->partial(mid + 1, mid + 1, m->width() - 1, m->width() - 1);
    return p;
}

Matrix *Matrix::_strassen_mul(Matrix *m1, Matrix *m2) {
    if (m1->width() != m2->height()){
        // exception
    }
    if (m1->width() <= 4 && m1->height() <= 4){
        return slow_mul(m1, m2);
    }
    Matrix* p1 = m1->clone(), *p2 = m2->clone();
    if (p1->width() < p1->height()){
        Matrix *st = new Matrix(p1->height(), p1->height() - p1->width(), 0);
        p1->hstack(st);
        Matrix* st2 = st->transpose();
        p2->vstack(st2);
        delete st;
        delete st2;
    }else if (p1->width() > p1->height()){
        Matrix *st = new Matrix(p1->width() - p1->height(), p1->width(), 0);
        p1->vstack(st);
        Matrix* st2 = st->transpose();
        p1->hstack(st2);
        delete st;
        delete st2;
    }
    if (p1->width() % 2){
        Matrix* st1 = new Matrix(1, p1->width(), 0);
        Matrix* st2 = new Matrix(p1->height() + 1, 1, 0);
        p1->vstack(st1);
        p1->hstack(st2);
        p2->vstack(st1);
        p2->hstack(st2);
        delete st1;
        delete st2;
    }
    auto d1 = _divide_four(p1);
    auto d2 = _divide_four(p2);

    // M1
    auto ad = add((*d1)[0], (*d1)[3]);
    auto bd = add((*d2)[0], (*d2)[3]);
    auto M1 = _strassen_mul(ad, bd);
    delete ad;
    delete bd;

    //M2
    ad = add((*d1)[2], (*d1)[3]);
    auto M2 = _strassen_mul(ad, (*d2)[0]);
    delete ad;

    //M3
    bd = sub((*d2)[1], (*d2)[3]);
    auto M3 = _strassen_mul((*d1)[0], bd);
    delete bd;

    //M4
    bd = sub((*d2)[2], (*d2)[3]);
    auto M4 = _strassen_mul((*d1)[3], bd);
    delete bd;

    //M5
    ad = add((*d1)[0], (*d2)[1]);
    auto M5 = _strassen_mul(ad, (*d2)[3]);
    delete ad;

    //M6
    ad = sub((*d1)[2], (*d1)[0]);
    bd = add((*d2)[0], (*d2)[1]);
    auto M6 = _strassen_mul(ad, bd);
    delete ad;
    delete bd;

    //M7
    ad = sub((*d1)[1], (*d1)[3]);
    bd = add((*d2)[2], (*d2)[3]);
    auto M7 = _strassen_mul(ad, bd);
    delete ad;
    delete bd;

    //C11
    auto mm = add(M1, M4);
    auto mmm = mm;
    mm = sub(mm, M5);
    delete mmm;
    auto C11 = add(mm, M7);
    delete mm;

    //C12
    auto C12 = add(M3, M5);

    //C21
    auto C21 = add(M2, M4);

    //C22
    mm = sub(M1, M2);
    mmm = mm;
    mm = add(mm, M3);
    delete mmm;
    auto C22 = add(mm, M6);
    delete mm;

    delete M1;
    delete M2;
    delete M3;
    delete M4;
    delete M5;
    delete M6;
    delete M7;

    C11->hstack(C12);
    C21->hstack(C22);
    C11->vstack(C21);
    delete C21;
    delete C12;
    delete C22;

    return C11;
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
    return nullptr;
}


