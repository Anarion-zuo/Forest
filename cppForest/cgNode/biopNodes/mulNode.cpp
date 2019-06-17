//
// Created by a on 2019/5/7.
//

#include "mulNode.h"

mulNode::mulNode(numericNode *parent, bool lr, numericNode *left, numericNode *right) : numericNode(parent, lr, left, right, 0) {}

double mulNode::_compute(double n1, double n2) {
    return n1 * n2;
}

numericNode *mulNode::clone(numericNode *parent) {
    numericNode* p = new mulNode(parent, _lr, nullptr, nullptr);
    p->_left = _left->clone(p);
    p->_right = _right->clone(p);
    return p;
}

numericNode *mulNode::diff() {
    numericNode* p = new addNode(_parent, _lr, nullptr, nullptr);
    numericNode* left = new mulNode(p, false, _left, _right);
    numericNode* right = new mulNode(p, true, nullptr, nullptr);
    _left->set_parent(left);
    _right->set_parent(left);
    right->_left = _left->clone(right);
    right->_right = _right->clone(right);
    p->_left = left;
    p->_right = right;

    p->_right->_right->_lr = true;
    p->_right->_left->_lr = false;

    left->_left = left->_left->diff();
    right->_right = right->_right->diff();

    return change_this(p);
}

numericNode *mulNode::trim() {
    _left = _left->trim();
    _right = _right->trim();
    if (_left->is_n_node(0)){
        return change_this(new constNode(_parent, _lr, 0));
    }else if (_right->is_n_node(0)) {
        return change_this(new constNode(_parent, _lr, 0));
    }
    numericNode* p = _change_if_both_const(this);
    return p;
}



