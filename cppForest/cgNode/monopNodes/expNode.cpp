//
// Created by a on 2019/5/14.
//

#include "expNode.h"
#include <cmath>

expNode::expNode(cgNode *parent, bool lr, cgNode *left) : monopNode(parent, lr, left) {}

monopNode *expNode::_clone(cgNode *parent) {
    return new expNode(parent, _lr, nullptr);
}



cgNode *expNode::_trim() {
    if (_left->is_const()){
        return change_this(new constNode(_parent, _lr, _compute(_left->_val)));
    }
    return this;
}

cgNode *expNode::diff() {
    cgNode* left = _left->diff();
    cgNode* mu = new mulNode(_parent, _lr, left, nullptr);
    cgNode* right = clone(mu);
    mu->_right = right;
    right->_lr = true;
    return change_this(mu);
}

double expNode::_compute(double n) {
    return exp(n);
}


