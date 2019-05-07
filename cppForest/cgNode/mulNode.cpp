//
// Created by a on 2019/5/7.
//

#include "mulNode.h"

mulNode::mulNode(cgNode *parent, bool lr, cgNode *left, cgNode *right) : cgNode(parent, lr, left, right, 0) {}

double mulNode::compute(double n1, double n2) {
    return n1 * n2;
}

cgNode *mulNode::clone(cgNode *parent) {
    cgNode* p = new mulNode(parent, _lr, nullptr, nullptr);
    p->_left = _left->clone(p);
    p->_right = _right->clone(p);
    return p;
}

cgNode *mulNode::diff() {
    cgNode* p = new addNode(_parent, _lr, nullptr, nullptr);
    cgNode* left = new mulNode(p, false, _left, _right);
    cgNode* right = new mulNode(p, true, nullptr, nullptr);
    right->_left = _left->clone(right);
    right->_right = _right->clone(right);
    p->_left = left;
    p->_right = right;
    left->_left = left->_left->diff();
    right->_right = right->_right->diff();
    return change_this(p);
}



