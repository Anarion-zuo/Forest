//
// Created by anarion on 6/11/19.
//

#include "var.h"

std::map<var*, var*> var::_temp_dvars;

var::var(double n) : _val(n) {}

void var::push_dvars(var *v1, var *v2) {
    _temp_dvars.insert(std::pair<var*, var*>(v1, v2));
}

void var::clear_dvars() {
    _temp_dvars.clear();
}

var *var::get_dvar(var *v) {
    auto it = _temp_dvars.find(v);
    if (it == _temp_dvars.end()){
        return nullptr;
    }
    return it->second;
}

var* var::register_this() {
    auto p = new var(0);
    push_dvars(this, p);
    return p;
}

const std::map<var *, var *> &var::get_map() {
    return _temp_dvars;
}

double var::get_val() {
    return _val;
}

void var::set_val(double n) {
    _val = n;
}

var* var::diff() {
    auto p = get_dvar(this);
    if (!p){
        p = register_this();
    }
    return p;
}

void var::change_range(double left, double right) {
    _range->set_left(left);
    _range->set_right(right);
}

double var::get_range_left() {
    return _range->get_left();
}

double var::get_range_right() {
    return _range->get_right();
}
