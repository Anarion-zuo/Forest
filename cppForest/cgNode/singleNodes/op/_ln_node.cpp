//
// Created by anarion on 6/18/19.
//

#include <tgmath.h>
#include "_ln_node.h"
#include "../number/_const_node.h"
#include "../../multiop/_mul_node.h"
#include "_pow_node.h"

_ln_node::_ln_node(_cg_node *parent, _cg_node *child) : _single_node(parent, child) {}

_cg_node *_ln_node::clone(_cg_node *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new _ln_node(parent, child);
    p->set_childs_parents();
    return p;
}

void _ln_node::compute() {
    _child->compute();
    if (!_result)   _result = new _const_node(this, 0);
    _result->set_val(log(_child->get_result()->get_val()));
}

void _ln_node::diff() {
    auto coef = _child->clone(nullptr);
    auto de = new _pow_node(nullptr, _child, -1);
    auto ret = new _mul_node(nullptr, coef, de);
    ret->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void _ln_node::trim() {

}
