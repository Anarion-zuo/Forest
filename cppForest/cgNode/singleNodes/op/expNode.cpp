//
// Created by anarion on 6/23/19.
//

#include <cmath>
#include "expNode.h"
#include "../number/constNode.h"
#include "../../multiop/mulNode.h"

expNode::expNode(cgNode *parent, cgNode *child) : singleNode(parent, child) {}

cgNode *expNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new expNode(parent, child);
    p->set_childs_parents();
    return p;
}

void expNode::compute() {
    _child->compute();
    _result = new constNode(this, exp(_child->get_result()->get_val()));
}

void expNode::diff() {
    auto coef = _child->clone(nullptr);
    auto ret = new mulNode(nullptr, coef, this);
    ret->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void expNode::trim() {

}
