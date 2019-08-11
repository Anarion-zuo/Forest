//
// Created by anarion on 2019/7/18.
//

#include <ctgmath>
#include "_cos_node.h"
#include "_sin_node.h"
#include "../../number/_const_node.h"
#include "../../../multiop/_mul_node.h"

_cos_node::_cos_node(_cg_node *parent, _cg_node *child) : _single_node(parent, child) {}

_cg_node *_cos_node::clone(_cg_node *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new _cos_node(parent, child);
    p->set_childs_parents();
    return p;
}

void _cos_node::compute() {
    _child->compute();
    _val = cos(_child->get_val());
}

void _cos_node::diff() {
    auto coef = _child->clone(nullptr);
    auto ret = new _mul_node(nullptr, new _mul_node(nullptr, new _const_node(nullptr, -1), coef), new _sin_node(nullptr, _child));
    ret->set_childs_parents();
    ret->get_child(0)->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void _cos_node::trim() {

}
