//
// Created by anarion on 6/11/19.
//

#include <ctgmath>
#include "powNode.h"

powNode::powNode(cgNode *parent, bool lr, cgNode *left, double pow) : monopNode(parent, lr, left), _pow(pow) {}

monopNode *powNode::_clone(cgNode *parent) {
    return new powNode(parent, _lr, nullptr, _pow);
}

double powNode::_compute(double n) {
    return pow(n, _pow);
}

cgNode *powNode::_trim() {
    if (_left->is_const()){
        return change_this(new constNode(_parent, _lr, _compute(_left->get_val())));
    }
    return this;
}

cgNode *powNode::diff() {
    _pow--;
    cgNode* p = new mulNode(nullptr, false, new constNode(nullptr, false, _pow), clone(nullptr));
    p->get_left()->set_parent(p);
    p->get_right()->set_parent(p);
    cgNode* right = clone(nullptr);
    right->set_lr(true);
    right = right->diff();
    cgNode* res = new mulNode(_parent, _lr, p, right);
    right->set_parent(res);
    p->set_parent(res);
    return change_this(res);
}
