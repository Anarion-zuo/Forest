//
// Created by anarion on 6/18/19.
//

#include "varNode.h"
#include "constNode.h"

varNode::varNode(cgNode *parent, var *pvar) : singleNode(parent, nullptr), _var(pvar) {}

cgNode *varNode::clone(cgNode *parent) {
    return new varNode(parent, _var);
}

void varNode::compute() {
    if (!_result){
        _result = new constNode(_parent, _var->get_val());
    }
    _result->set_val(_var->get_val());
}

double varNode::get_val() {
    return _var->get_val();
}

void varNode::set_val(double val) {
    _var->set_val(val);
}

void varNode::diff() {
    _var = _var->diff();
}

void varNode::trim() {}

bool varNode::is_num() {
    return true;
}
