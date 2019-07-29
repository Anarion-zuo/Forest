//
// Created by anarion on 7/8/19.
//

#include <ctgmath>
#include "Range.h"
#include "../MyException/RangeException/RangeMagException.h"

Range::Range(double left, double right) : _left(left), _right(right) {
    if (_left > _right){
        throw RangeMagException(left, right);
    }
}

Range *Range::clone() {
    return new Range(_left, _right);
}

std::vector<double> Range::list(double step) {
    size_t n = floor((_right - _left) / step);
    std::vector<double> ret(n);
    double an = _left;
    for (auto &i : ret){
        i = an;
        an += step;
    }
    return std::move(ret);
}

bool Range::is_in(double n) {
    return n < _right && n > _left;
}

bool Range::is_on_left(double n) {
    return n < _left;
}

bool Range::is_on_right(double n) {
    return n > _right;
}

double Range::get_right() {
    return _right;
}

double Range::get_left() {
    return _left;
}

void Range::register_var_range(var *x, double left, double right) {

}
