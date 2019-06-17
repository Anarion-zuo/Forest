//
// Created by a on 2019/5/14.
//

#include "expNode.h"
#include <cmath>

expNode::expNode(numericNode *parent, bool lr, numericNode *left) : monopNode(parent, lr, left) {}

monopNode *expNode::_clone(numericNode *parent) {
    return new expNode(parent, _lr, nullptr);
}

numericNode *expNode::_trim() {
    if (_left->is_const()){
        return change_this(new constNode(_parent, _lr, _compute(_left->_val)));
    }
    return this;
}

numericNode *expNode::diff() {
    numericNode* left = _left->diff();
    numericNode* mu = new mulNode(_parent, _lr, left, nullptr);
    numericNode* right = clone(mu);
    mu->_right = right;
    right->_lr = true;
    return change_this(mu);
}

double expNode::_compute(double n) {
    return exp(n);
}


