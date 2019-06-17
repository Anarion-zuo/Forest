//
// Created by a on 2019/5/14.
//

#include "monopNode.h"

monopNode::monopNode(numericNode *parent, bool lr, numericNode *left) : numericNode(parent, lr, left, nullptr, 0) {}

numericNode *monopNode::clone(numericNode *parent) {
    monopNode* p = _clone(parent);
    p->_left = _left->clone(p);
    p->_right = nullptr;
    return p;
}

numericNode *monopNode::trim() {
    _left = _left->trim();
    return _trim();
}

double monopNode::compute() {
    _val = _compute(_left->compute());
    return _val;
}

