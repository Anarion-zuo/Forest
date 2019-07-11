//
// Created by anarion on 6/17/19.
//

#include "cgNode.h"
#include "../MyException/VectorException/functionCallException/getnonconstValException.h"
#include "../MyException/nullException.h"

std::deque<cgNode*> cgNode::_node_bin;

cgNode::cgNode(cgNode *parent, const std::vector<cgNode *> &childs) : _parent(parent), _childs(childs) {
//    for (auto i : _childs){
//        i->set_parent(this);
//    }
}


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

cgNode* cgNode::get_child(size_t index) {
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

size_t cgNode::find_in_parent() {
    auto pc = _parent->get_childs();
    for (size_t i = 0; i < _parent->number_child(); ++i){
        if (pc[i] == this){
            return i;
        }
    }
    return -1;
}

double cgNode::get_val() {
    throw getnonconstValException(this);
}

void cgNode::set_val(double val) {

}

//std::string &&cgNode::to_string() {
//    std::string res;
//    res += "<" + string_name() + ">\n\t";
//    for (auto i : _childs){
//        res += i->string_name();
//    }
//    res += "</" + string_name() + ">\n";
//    return std::move(res);
//}

void cgNode::set_child(size_t index, cgNode *node) {
    _childs[index] = node;
}

bool cgNode::is_const() {
    return false;
}

void cgNode::change_to(cgNode *oldnode, cgNode *newnode) {
    if (!oldnode){
        throw nullException("Attempting to change a null target.");
    }
    if (!newnode){
        __glibc_macro_warning("Attempting to change a node into a null node.");
    }
    cgNode* parent = oldnode->_parent;
    size_t index = oldnode->find_in_parent();
    parent->set_child(index, newnode);
    if (newnode)    newnode->_parent = parent;
}

void cgNode::_del_as_node(cgNode *&node) {
    if (!node){
        return;
    }
    for (auto & _child : node->_childs){
        _child->set_parent(nullptr);
    }
    delete node;
    node = nullptr;
}

void cgNode::_del_as_root(cgNode *&node) {
    if (!node){
        return;
    }
    _del_as_root_recur(node);
    delete node;
    node = nullptr;
}

void cgNode::_del_as_root_recur(cgNode *&node) {
    if (!node){
        return;
    }
    for (auto & child : node->_childs){
        if (!child){
            _del_as_root_recur(child);
            delete child;
        }
    }
}

void cgNode::_throw_away(cgNode *node) {
    if (!node){
        return;
    }
    _node_bin.push_back(node);
}

void cgNode::_clear_bin() {
    for (auto & i : _node_bin){
        _del_as_node(i);
    }
    _node_bin.clear();
}

void cgNode::_retrieve_bin() {
    while (!_node_bin.empty()){
        _node_bin.pop_back();
    }
}

cgNode::~cgNode() {
    delete _result;
}

