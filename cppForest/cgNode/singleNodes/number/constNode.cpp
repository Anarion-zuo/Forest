//
// Created by anarion on 6/18/19.
//

#include "constNode.h"

constNode::constNode(cgNode *parent, double val) : singleNode(parent, nullptr), _val(val){

}

cgNode *constNode::clone(cgNode *parent) {
    return new constNode(parent, _val);
}

void constNode::compute() {
    _result = this;
}

double constNode::get_val() {
    return _val;
}

void constNode::set_val(double val) {
    _val = val;
}

void constNode::diff() {

}

void constNode::trim() {

}
