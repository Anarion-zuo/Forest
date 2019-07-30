//
// Created by anarion on 6/18/19.
//

#include "_const_node.h"

_const_node::_const_node(_cg_node *parent, double val) : _single_node(parent, nullptr), _val(val){

}

_cg_node *_const_node::clone(_cg_node *parent) {
    return new _const_node(parent, _val);
}

void _const_node::compute() {
    _result = this;
}

double _const_node::get_val() {
    return _val;
}

void _const_node::set_val(double val) {
    _val = val;
}

void _const_node::diff() {
    _val = 0;
}

void _const_node::trim() {

}

bool _const_node::is_const() {
    return true;
}

bool _const_node::is_num() {
    return true;
}
