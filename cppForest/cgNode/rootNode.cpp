//
// Created by anarion on 7/7/19.
//

#include "rootNode.h"

rootNode::rootNode(cgNode *child) : cgNode(nullptr, {child}), _child(_childs[0]) {}

cgNode *rootNode::clone(cgNode *parent) {
    auto node = _child->clone(this);
    return new rootNode(node);
}

void rootNode::compute() {
    _child->compute();
    _result = _child->get_result();
}

void rootNode::diff() {
    _child->diff();
}

void rootNode::trim() {

}
