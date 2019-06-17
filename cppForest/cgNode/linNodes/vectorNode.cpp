//
// Created by anarion on 6/13/19.
//

#include "vectorNode.h"

bool vectorNode::is_vector() {
    return true;
}

vectorNode::vectorNode(numericNode *parent, bool lr, const std::vector<numericNode *> &childs) : numericNode(parent, lr, nullptr, nullptr, 0), _childs(childs) {}

void vectorNode::del() {
    for (auto & _child : _childs){
        if (_child){
            _child->del();
            delete _child;
        }
    }
}

vectorNode *vectorNode::clone(numericNode *parent) {
    return new vectorNode(parent, _lr, _childs);
}

double vectorNode::_compute(double n1, double n2) {
    return 0;
}

numericNode *vectorNode::trim() {
    for (auto &_child : _childs){
        if (_child){
            _child = _child->trim();
        }
    }
    return this;
}

numericNode *vectorNode::diff() {
    for (auto &_child : _childs){
        if (_child){
            _child = _child->diff();
        }
    }
    return this;
}
