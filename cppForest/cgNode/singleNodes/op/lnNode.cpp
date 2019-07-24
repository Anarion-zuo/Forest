//
// Created by anarion on 6/18/19.
//

#include <tgmath.h>
#include "lnNode.h"
#include "../number/constNode.h"
#include "../../multiop/mulNode.h"
#include "powNode.h"

lnNode::lnNode(cgNode *parent, cgNode *child) : singleNode(parent, child) {}

cgNode *lnNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new lnNode(parent, child);
    p->set_childs_parents();
    return p;
}

void lnNode::compute() {
    _child->compute();
    if (!_result)   _result = new constNode(this, 0);
    _result->set_val(log(_child->get_result()->get_val()));
}

void lnNode::diff() {
    auto coef = _child->clone(nullptr);
    auto de = new powNode(nullptr, _child, -1);
    auto ret = new mulNode(nullptr, coef, de);
    ret->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void lnNode::trim() {

}
