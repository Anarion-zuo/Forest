//
// Created by anarion on 7/8/19.
//

#include <tgmath.h>
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

const std::vector<double> Range::list(double step) {
    size_t n = floor((_right - _left) / step);
    std::vector<double> ret(n);
    double an = _left;
    for (auto &i : ret){
        i = an;
        an += step;
    }
    return std::move(ret);
}
