//
// Created by a on 2019/5/7.
//

#include "cgNode.h"
#include <cmath>

cgNode::cgNode(cgNode *parent, bool lr, cgNode *left, cgNode *right, double val)
: _parent(parent), _lr(lr), _left(left), _right(right), _val(val) {}

bool cgNode::num_equals(double n1, double n2) {
   double d = n1 - n2;
   if (d < 0){d = -d;}
   return d < std::numeric_limits<double>::epsilon() * 16;
}

bool cgNode::is_n_node(double n) {
    return false;
}

bool cgNode::is_var() {
    return false;
}

bool cgNode::is_const() {
    return false;
}

cgNode *cgNode::change_this(cgNode *node) {
    if (_lr){
        _parent->_right = node;
    }else{
        _parent->_left = node;
    }
    node->_lr = _lr;
    node->_parent = _parent;
    Garbage_Bin::push(this);
    return node;
}

void cgNode::set_var(double val) {
    _val = val;
}

double cgNode::get_val() {
    return _val;
}

cgNode *cgNode::get_parent() {
    return _parent;
}

bool cgNode::get_lr() {
    return _lr;
}

cgNode *cgNode::get_left() {
    return _left;
}

cgNode *cgNode::get_right() {
    return _right;
}



