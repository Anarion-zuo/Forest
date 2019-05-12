//
// Created by a on 2019/5/11.
//

#include "varNode.h"

std::map<cgNode*, varNode*> _temp_dvars;

varNode::varNode(double val) : cgNode(nullptr, false, nullptr, nullptr, val) {}

cgNode *varNode::clone(cgNode *parent) {
    return this;
}

double varNode::compute(double n1, double n2) {
    return _val;
}

cgNode *varNode::trim() {
    return this;
}

cgNode *varNode::diff() {
    varNode* dv = get_dvar(this);
    if (dv){
        return dv;
    }
    dv = new varNode(0);
    push_dvars(this, dv);
    return dv;
}

void varNode::del() {}

void varNode::push_dvars(cgNode *n1, varNode *n2) {
    _temp_dvars.insert(std::pair<cgNode*, varNode*>(n1, n2));
}

void varNode::clear_dvars() {
    _temp_dvars.clear();
}

varNode *varNode::get_dvar(cgNode *node) {
    auto it = _temp_dvars.find(node);
    if (it == _temp_dvars.end()){
        return nullptr;
    }
    return it->second;
}


