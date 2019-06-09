//
// Created by anarion on 19-5-31.
//

#include <cmath>
#include "Array.h"

Array::Array() {}

Array::Array(const std::vector<double> &c) : _c(c) {}

Array::Array(size_t n, double a) : _c(n, a) {}

size_t Array::size() {
    return _c.size();
}

double Array::sum() {
    double res = 0;
    for (size_t i = 0; i < size(); ++i){
        res += _c[i];
    }
    return res;
}

double Array::prod() {
    double res = 0;
    for (size_t i = 0; i < size(); ++i){
        res *= _c[i];
    }
    return res;
}

double Array::mean() {
    return sum() / size();
}

double Array::moment(size_t n) {
    double res = 0;
    for (size_t i = 0; i < size(); ++i){
        res += pow(_c[i], n);
    }
    return res / size();
}

double Array::nth_item(size_t n) {
    return 0;
}

double Array::most_frequent() {
    return 0;
}

double &Array::operator[](size_t n) {
    return _c[n];
}

std::vector<size_t> Array::find(double a) {
    std::vector<size_t> res;
    for (size_t i = 0; i < size(); ++i){
        if (_c[i] == a){
            _c.push_back(i);
        }
    }
    return res;
}

size_t Array::count(double a) {
    size_t res = 0;
    for (size_t i = 0; i < size(); ++i){
        if (_c[i] == a){
            ++res;
        }
    }
    return res;
}

bool Array::has(double a) {
    return count(a) != 0;
}

void Array::push_back(double a) {
    _c.push_back(a);
}

void Array::del_back() {
    _c.pop_back();
}

void Array::push_at(double a, size_t n) {
    _c.insert(_c.begin() + n, a);
}

void Array::del_at(size_t n) {
    _c.erase(_c.begin() + n);
}

Array *Array::clone() {
    return new Array(_c);
}

Array *Array::add(Array *x, Array *y) {
    if (!x || !y){
        // exception
    }
    if (x->size() != y->size()){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] + (*y)[i];
    }
    return p;
}

Array *Array::sub(Array *x, Array *y) {
    if (!x || !y){
        // exception
    }
    if (x->size() != y->size()){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] - (*y)[i];
    }
    return p;
}

Array *Array::mul(Array *x, Array *y) {
    if (!x || !y){
        // exception
    }
    if (x->size() != y->size()){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] * (*y)[i];
    }
    return p;
}

Array *Array::div(Array *x, Array *y) {
    if (!x || !y){
        // exception
    }
    if (x->size() != y->size()){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] / (*y)[i];
    }
    return p;
}

Array *Array::add(Array *x, double y) {
    if (!x){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] + y;
    }
    return p;
}

Array *Array::sub(Array *x, double y) {
    if (!x){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] - y;
    }
    return p;
}

Array *Array::mul(Array *x, double y) {
    if (!x){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] * y;
    }
    return p;
}

Array *Array::div(Array *x, double y) {
    if (!x){
        // exception
    }
    Array* p = new Array(x->size(), 0);
    for (size_t i = 0; i < x->size(); ++i){
        (*p)[i] = (*x)[i] / y;
    }
    return p;
}

double Array::dot(Array *x, Array *y) {
    Array* p = mul(x, y);
    double res = p->sum();
    delete p;
    return res;
}

void Array::stack(Array *a) {
    if (!a){
        // exception
    }
    _c.insert(_c.end(), a->_c.begin(), a->_c.end());
}

std::string Array::to_string() {
    if (_c.empty()){
        return "empty array";
    }
    std::string str;
    for (size_t i = 0; i < _c.size(); ++i){
        str += std::to_string(_c[i]);
        if (i != _c.size() - 1){
            str += ',';
        }else{
            str += '\n';
        }
    }
}


