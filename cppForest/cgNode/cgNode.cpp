//
// Created by anarion on 6/17/19.
//

#include "cgNode.h"

cgNode::cgNode(cgNode *parent, const std::vector<cgNode *> &childs) : _parent(parent), _childs(childs) {}


void cgNode::set_childs_parents() {
    for (auto &i : _childs){
        i->set_parent(this);
    }
}

size_t cgNode::number_child() {
    return _childs.size();
}

cgNode *cgNode::get_parent() {
    return _parent;
}

std::vector<cgNode *> &cgNode::get_childs() {
    return _childs;
}

cgNode *&cgNode::get_child(size_t index) {
    return _childs[index];
}

void cgNode::set_parent(cgNode *node) {
    _parent = node;
}

bool cgNode::is_single_val() {
    return false;
}

cgNode *cgNode::get_result() {
    return _result;
}

size_t cgNode::index_parent() {
    auto pc = _parent->get_childs();
    for (size_t i = 0; i < _parent->number_child(); ++i){
        if (pc[i] == this){
            return i;
        }
    }
}

double cgNode::get_val() {
    return 0;
}

void cgNode::set_val(double val) {

}

