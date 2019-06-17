//
// Created by a on 2019/5/11.
//

#include "constNode.h"

constNode::constNode(numericNode *parent, bool lr, double val) : numericNode(parent, lr, nullptr, nullptr, val) {}

numericNode *constNode::clone(numericNode *parent) {
    numericNode* p = new constNode(parent, _lr, _val);
    return p;
}

double constNode::compute() {
    return _val;
}

numericNode *constNode::trim() {
    return this;
}

numericNode *constNode::diff() {
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
