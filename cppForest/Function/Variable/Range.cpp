//
// Created by anarion on 6/11/19.
//

#include "Range.h"

Range::Range(double left, double right) : _left(left), _right(right) {
    if (left > right){
        throw "Fault range.";
    }
}

bool Range::is_in(double n) {
    return _left <= n && _right >= n;
}

bool Range::is_in(Range *range) {
    return _left <= range->_left && _right >= range->_right;
}

bool Range::on_right(Range *range) {
    return _right <= range->_left;
}

bool Range::on_right(double n) {
    return n >= _right;
}

bool Range::on_left(Range *range) {
    return range->_right <= _left;
}

bool Range::on_left(double n) {
    return n <= _left;
}

void Range::set_left(double n) {
    _left = n;
}

double Range::get_left() {
    return _left;
}

void Range::set_right(double n) {
    _right = n;
}

double Range::get_right() {
    return _right;
}

Range *Range::clone() {
    return new Range(_left, _right);
}
