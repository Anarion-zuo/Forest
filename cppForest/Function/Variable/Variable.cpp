//
// Created by anarion on 6/11/19.
//

#include "Variable.h"

Variable::Variable(double n, double left, double right) : _range(new Range(left, right)), _var(new var(n)) {}

Variable::~Variable() {
    delete _range;
    delete _var;
}

void Variable::change_range(double left, double right) {
    _range->set_left(left);
    _range->set_right(right);
}

double Variable::get_range_left() {
    return _range->get_left();
}

double Variable::get_range_right() {
    return _range->get_right();
}
