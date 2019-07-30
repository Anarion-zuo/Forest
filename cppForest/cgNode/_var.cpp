//
// Created by anarion on 6/11/19.
//

#include "_var.h"

std::set<_var*> _var::_vars_set;
std::map<_var *, _var *> _var::_dvars_map;

_var::_var(double n) : _val(n) {
    _vars_set.insert(this);
}

void _var::push_dvars(_var *v1, _var *v2) {
    _dvars_map.insert(std::pair<_var *, _var *>(v1, v2));
}

void _var::clear_dvars() {
    _dvars_map.clear();
}

_var *_var::get_dvar(_var *v) {
    auto it = _dvars_map.find(v);
    if (it == _dvars_map.end()) {
        return nullptr;
    }
    return it->second;
}

_var *_var::register_this() {
    auto p = new _var(0);
    push_dvars(this, p);
    return p;
}

const std::map<_var *, _var *> &_var::get_map() {
    return _dvars_map;
}

double _var::get_val() {
    return _val;
}

void _var::set_val(double n) {
    _val = n;
}

_var *_var::diff() {
    auto p = get_dvar(this);
    if (!p) {
        p = register_this();
    }
    return p;
}

_var::~_var() {
    _vars_set.erase(this);
}

std::map<_var*,_var*>::iterator _var::set_dvar(_var *v) {
    auto it = _dvars_map.find(v);
    it->second->set_val(1);
    return it;
}

void _var::clear_dvar(const std::map<_var*,_var*>::iterator& it) {
    it->second->set_val(0);
}
