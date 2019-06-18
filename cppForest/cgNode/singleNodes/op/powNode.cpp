//
// Created by anarion on 6/18/19.
//

#include <tgmath.h>
#include "powNode.h"
#include "../number/constNode.h"

powNode::powNode(cgNode *parent, cgNode *child, double pow) : singleNode(parent, child), _pow(pow) {}

cgNode *powNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new powNode(parent, child, _pow);
    p->set_childs_parents();
    return p;
}

void powNode::compute() {
    _child->compute();
    _result = new constNode(this, pow(_child->get_result()->get_val(), _pow));
}
