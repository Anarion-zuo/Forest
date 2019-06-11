//
// Created by a on 2019/5/7.
//

#include "addNode.h"
#include "mulNode.h"

double addNode::_compute(double n1, double n2) {
    return n1 + n2;
}

cgNode *addNode::trim() {
    _left = _left->trim();
    _right = _right->trim();
    if (_left->is_n_node(0)){
        return change_this(_right);
    }else if (_right->is_n_node(0)) {
        return change_this(_left);
    }
//    else if (_left->is_identical(_right)){
//        return change_this(new mulNode(_parent, _lr, _left, new constNode(this, true, 2)));
//    }
    cgNode* p = _change_if_both_const(this);
    return p;
}

cgNode *addNode::diff() {
    _left = _left->diff();
    _right = _right->diff();
    return this;
}

cgNode *addNode::clone(cgNode* parent) {
    cgNode* p = new addNode(parent, _lr, nullptr, nullptr);
    p->_left = _left->clone(p);
    p->_right = _right->clone(p);
    return p;
}

addNode::addNode(cgNode *parent, bool lr, cgNode *left, cgNode *right) : cgNode(parent, lr, left, right, 0) {}
