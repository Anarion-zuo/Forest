//
// Created by anarion on 6/18/19.
//

#include "_var_node.h"
#include "_const_node.h"

_var_node::_var_node(_cg_node *parent, _var *pvar) : _single_node(parent, nullptr), _x(pvar) {}

_cg_node *_var_node::clone(_cg_node *parent) {
    return new _var_node(parent, _x);
}

void _var_node::compute() {
    _val = _x->get_val();
}

void _var_node::diff() {
    _x = _x->diff();
}

void _var_node::trim() {}

bool _var_node::is_num() {
    return true;
}
