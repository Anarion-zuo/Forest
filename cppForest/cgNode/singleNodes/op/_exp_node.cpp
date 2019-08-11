//
// Created by anarion on 6/23/19.
//

#include <cmath>
#include "_exp_node.h"
#include "../number/_const_node.h"
#include "../../multiop/_mul_node.h"

_exp_node::_exp_node(_cg_node *parent, _cg_node *child) : _single_node(parent, child) {}

_cg_node *_exp_node::clone(_cg_node *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new _exp_node(parent, child);
    p->set_childs_parents();
    return p;
}

void _exp_node::compute() {
    _child->compute();
    _val = exp(_child->get_val());
}

void _exp_node::diff() {
    auto coef = _child->clone(nullptr);
    auto ret = new _mul_node(nullptr, coef, this);
    ret->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void _exp_node::trim() {

}
