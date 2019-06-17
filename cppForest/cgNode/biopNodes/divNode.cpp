//
// Created by a on 2019/5/7.
//

#include "divNode.h"
#include "../monopNodes/powNode.h"

divNode::divNode(numericNode *parent, bool lr, numericNode *left, numericNode *right) : numericNode(parent, lr, left, right, 0) {}

numericNode *divNode::clone(numericNode *parent) {
    numericNode* p = new divNode(parent, _lr, nullptr, nullptr);
    p->_left = _left->clone(p);
    p->_right = _right->clone(p);
    return p;
}

numericNode *divNode::diff() {
    numericNode* p = new divNode(_parent, _lr, nullptr, nullptr);
    numericNode* up = new subNode(
            p,
            false,
            new mulNode(nullptr, false, _left, _right),
            new mulNode(nullptr, true, _left->clone(nullptr), _right->clone(nullptr))
            );
    up->_left->_parent = up;
    up->_right->_parent = up;
    up->_right->_left->_parent = up->_right;
    up->_right->_left->_lr = false;
    up->_right->_right->_parent = up->_right;
    up->_right->_right->_lr = true;
    p->_left = up;
    p->_right = new powNode(p, true, _right->clone(nullptr), 2);
    p->_right->get_left()->set_parent(p->_right);
    p->_right->_lr = true;
    up->_left->_left = up->_left->_left->diff();
    up->_right->_right = up->_right->_right->diff();
    return change_this(p);
}

double divNode::_compute(double n1, double n2) {
    return n1 / n2;
}

numericNode *divNode::trim() {
    if (_left->is_n_node(0)){
        return change_this(new constNode(_parent, _lr, 0));
    }else if (_right->is_n_node(0)) {
        throw "Dividing by 0.";
    }else if (_right->is_n_node(1)){
        return change_this(_left);
    }
    numericNode* p = _change_if_both_const(this);
    return p;
}
