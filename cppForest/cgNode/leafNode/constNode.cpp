//
// Created by a on 2019/5/11.
//

#include "constNode.h"

constNode::constNode(cgNode *parent, bool lr, double val) : cgNode(parent, lr, nullptr, nullptr, val) {}

cgNode *constNode::clone(cgNode *parent) {
    cgNode* p = new constNode(parent, _lr, _val);
    return p;
}

double constNode::compute() {
    return _val;
}

cgNode *constNode::trim() {
    return this;
}

cgNode *constNode::diff() {
    _val = 0;
    return this;
}

void constNode::del() {}

bool constNode::is_const() {
    return true;
}

bool constNode::is_n_node(double n) {
    return _val == n;
}
