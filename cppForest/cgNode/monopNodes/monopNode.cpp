//
// Created by a on 2019/5/14.
//

#include "monopNode.h"

monopNode::monopNode(cgNode *parent, bool lr, cgNode *left) : cgNode(parent, lr, left, nullptr, 0) {}

cgNode *monopNode::clone(cgNode *parent) {
    monopNode* p = _clone(parent);
    p->_left = _left->clone(p);
    p->_right = nullptr;
    return p;
}

cgNode *monopNode::trim() {
    _left = _left->trim();
    return _trim();
}

double monopNode::compute() {
    _val = _compute(_left->compute());
    return _val;
}

