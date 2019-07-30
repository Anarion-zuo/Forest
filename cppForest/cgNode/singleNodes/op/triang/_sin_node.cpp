//
// Created by anarion on 2019/7/18.
//

#include <ctgmath>
#include "_sin_node.h"
#include "../../number/_const_node.h"
#include "../../../multiop/_mul_node.h"
#include "_cos_node.h"

_sin_node::_sin_node(_cg_node *parent, _cg_node *child) : _single_node(parent, child) {

}

_cg_node *_sin_node::clone(_cg_node *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new _sin_node(parent, child);
    p->set_childs_parents();
    return p;
}

void _sin_node::compute() {
    _child->compute();
    if (!_result)   _result = new _const_node(this, 0);
    _result->set_val(sin(_child->get_result()->get_val()));
}

void _sin_node::diff() {
    auto coef = _child->clone(nullptr);
    auto ret = new _mul_node(nullptr, coef, new _cos_node(nullptr, _child));
    ret->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void _sin_node::trim() {

}
