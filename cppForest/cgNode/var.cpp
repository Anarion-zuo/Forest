//
// Created by anarion on 6/11/19.
//

#include "var.h"

std::set<var*> var::_vars_set;
std::map<var *, var *> var::_dvars_map;

var::var(double n) : _val(n) {
    _vars_set.insert(this);
}

void var::push_dvars(var *v1, var *v2) {
    _dvars_map.insert(std::pair<var *, var *>(v1, v2));
}

void var::clear_dvars() {
    _dvars_map.clear();
}

var *var::get_dvar(var *v) {
    auto it = _dvars_map.find(v);
    if (it == _dvars_map.end()) {
        return nullptr;
    }
    return it->second;
}

var *var::register_this() {
    auto p = new var(0);
    push_dvars(this, p);
    return p;
}

const std::map<var *, var *> &var::get_map() {
    return _dvars_map;
}

double var::get_val() {
    return _val;
}

void var::set_val(double n) {
    _val = n;
}

var *var::diff() {
    auto p = get_dvar(this);
    if (!p) {
        p = register_this();
    }
    return p;
}

var::~var() {
    _vars_set.erase(this);
}
