//
// Created by a on 2019/5/7.
//

#include "subNode.h"
double subNode::_compute(double n1, double n2) {
    return n1 - n2;
}

numericNode *subNode::trim() {
    _left = _left->trim();
    _right = _right->trim();
    if (_right->is_n_node(0)) {
        return change_this(_left);
    }
//    else if (_left->is_identical(_right)){
//        return change_this(new mulNode(_parent, _lr, _left, new constNode(this, true, 2)));
//    }
    numericNode* p = _change_if_both_const(this);
    return p;
}

numericNode *subNode::diff() {
    _left = _left->diff();
    _right = _right->diff();
    return this;
}

numericNode *subNode::clone(numericNode* parent) {
    numericNode* p = new subNode(parent, _lr, nullptr, nullptr);
    p->_left = _left->clone(p);
    p->_right = _right->clone(p);
    return p;
}

subNode::subNode(numericNode *parent, bool lr, numericNode *left, numericNode *right) : numericNode(parent, lr, left, right, 0) {}