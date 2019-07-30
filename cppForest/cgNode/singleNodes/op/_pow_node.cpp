//
// Created by anarion on 6/18/19.
//

#include <tgmath.h>
#include "_pow_node.h"
#include "../number/_const_node.h"
#include "../../multiop/_mul_node.h"

_pow_node::_pow_node(_cg_node *parent, _cg_node *child, double pow) : _single_node(parent, child), _pow(pow) {}

_cg_node *_pow_node::clone(_cg_node *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new _pow_node(parent, child, _pow);
    p->set_childs_parents();
    return p;
}

void _pow_node::compute() {
    _child->compute();
    _result = new _const_node(this, pow(_child->get_result()->get_val(), _pow));
}

void _pow_node::diff() {
    auto left = new _const_node(nullptr, _pow);
    auto right = new _pow_node(nullptr, _child, _pow - 1);
    auto ret = new _mul_node(nullptr, left, right);
    auto dch = _child->clone(nullptr);
    auto ret2 = new _mul_node(nullptr, ret, dch);
    ret2->set_childs_parents();
    dch->diff();
    change_to(this, ret2);
}

void _pow_node::trim() {

}
