//
// Created by a on 2019/5/14.
//

#include "expNode.h"
#include <cmath>

expNode::expNode(cgNode *parent, bool lr, cgNode *left, cgNode *right) : cgNode(parent, lr, left, right, 0) {}

cgNode *expNode::clone(cgNode *parent) {
    cgNode* p = new expNode(parent, _lr, nullptr, nullptr);
    p->_left = _left->clone(p);
    p->_right = _right->clone(p);
    return p;
}

double expNode::compute(double n1, double n2) {
    return pow(n1, n2);
}

cgNode *expNode::trim() {
    return this;
}

cgNode *expNode::diff() {
    return this;
}
