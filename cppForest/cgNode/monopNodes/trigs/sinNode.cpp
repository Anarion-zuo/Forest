//
// Created by a on 2019/5/15.
//

#include <cmath>
#include "sinNode.h"
#include "cosNode.h"

sinNode::sinNode(numericNode *parent, bool lr, numericNode *left) : monopNode(parent, lr, left) {}

monopNode *sinNode::_clone(numericNode *parent) {
    return new sinNode(parent, _lr, nullptr);
}

double sinNode::_compute(double n) {
    return sin(n);
}

numericNode *sinNode::_trim() {
    if (_left->is_const()){
        change_this(new constNode(_parent, _lr, sin(_left->get_val())));
    }
    return this;
}

numericNode *sinNode::diff() {
    return change_this(new cosNode(_parent, _lr, _left));
}
