//
// Created by a on 2019/5/11.
//

#include "varNode.h"

varNode::varNode(numericNode* parent, bool lr, var* v) : numericNode(parent, lr, nullptr, nullptr, 0), _var(v) {}

numericNode *varNode::clone(numericNode *parent) {
    return new varNode(parent, _lr, _var);
}

double varNode::compute() {
    _val = _var->get_val();
    return _val;
}

numericNode *varNode::trim() {
    return this;
}

numericNode *varNode::diff() {
    set_var(_var->diff());
    return this;
}

void varNode::del() {}


bool varNode::is_var() {
    return true;
}

void varNode::set_var(var *v) {
    _var = v;
}

var *varNode::get_var() {
    return _var;
}


