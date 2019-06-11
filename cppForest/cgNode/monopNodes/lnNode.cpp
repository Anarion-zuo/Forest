//
// Created by a on 2019/5/14.
//

#include "lnNode.h"
#include <cmath>

lnNode::lnNode(cgNode *parent, bool lr, cgNode *left) : monopNode(parent, lr, left) {}

monopNode *lnNode::_clone(cgNode *parent) {
    return new lnNode(parent, _lr, nullptr);
}

double lnNode::_compute(double n) {
    return log(n);
}

cgNode *lnNode::_trim() {
    return this;
}

cgNode *lnNode::diff() {
    cgNode* p = new divNode(nullptr, _lr, _left, _left->clone(nullptr));
    p->_left->_parent = p;
    p->_left->_lr = false;
    p->_right->_parent = p;
    p->_right->_lr = true;
    p->_left = p->_left->diff();
    return p;
}

