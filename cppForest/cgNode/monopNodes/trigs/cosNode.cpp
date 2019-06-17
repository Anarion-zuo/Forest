//
// Created by anarion on 6/9/19.
//

#include <cmath>
#include "cosNode.h"
#include "sinNode.h"

cosNode::cosNode(numericNode *parent, bool lr, numericNode *left) : monopNode(parent, lr, left) {}

monopNode *cosNode::_clone(numericNode *parent) {
    return new cosNode(parent, _lr, nullptr);
}

double cosNode::_compute(double n) {
    return cos(n);
}

numericNode *cosNode::_trim() {
    if (_left->is_const()){
        change_this(new constNode(_parent, _lr, cos(_left->get_val())));
    }
    return this;
}

numericNode *cosNode::diff() {
    auto p = new mulNode(_parent, _lr, new constNode(nullptr, false, -1), new sinNode(nullptr, true, _left));
    p->get_left()->set_parent(p);
    p->get_right()->set_parent(p);
    return change_this(p);
}