//
// Created by anarion on 7/7/19.
//

#include "rootNode.h"

rootNode::rootNode(cgNode *child) : cgNode(nullptr, {child}), _child(_childs[0]) {}

cgNode *rootNode::clone(cgNode *parent) {
    _child = _child->clone(this);
    return this;
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
