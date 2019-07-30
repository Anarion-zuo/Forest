//
// Created by anarion on 6/17/19.
//

#include "_cg_node.h"
#include "../MyException/VectorException/functionCallException/getnonconstValException.h"
#include "../MyException/nullException.h"

std::deque<_cg_node*> _cg_node::_node_bin;

_cg_node::_cg_node(_cg_node *parent, const std::vector<_cg_node *> &childs) : _parent(parent), _childs(childs) {
//    for (auto i : _childs){
//        i->set_parent(this);
//    }
}


void _cg_node::set_childs_parents() {
    if (is_num()){
        return;
    }
    for (auto i : _childs){
        i->set_parent(this);
//        i->set_childs_parents();
    }
}

size_t _cg_node::number_child() {
    return _childs.size();
}

_cg_node *_cg_node::get_parent() {
    return _parent;
}

std::vector<_cg_node *> &_cg_node::get_childs() {
    return _childs;
}

_cg_node* _cg_node::get_child(size_t index) {
    return _childs[index];
}

void _cg_node::set_parent(_cg_node *node) {
    _parent = node;
}

bool _cg_node::is_single_val() {
    return false;
}

_cg_node *_cg_node::get_result() {
    return _result;
}

size_t _cg_node::find_in_parent() {
    auto pc = _parent->get_childs();
    for (size_t i = 0; i < pc.size(); ++i){
        if (pc[i] == this){
            return i;
        }
    }
    return -1;
}

double _cg_node::get_val() {
    throw getnonconstValException(this);
}

void _cg_node::set_val(double val) {

}

//std::string &&_cg_node::to_string() {
//    std::string res;
//    res += "<" + string_name() + ">\n\t";
//    for (auto i : _childs){
//        res += i->string_name();
//    }
//    res += "</" + string_name() + ">\n";
//    return std::move(res);
//}

void _cg_node::set_child(size_t index, _cg_node *node) {
    _childs[index] = node;
}

bool _cg_node::is_const() {
    return false;
}

void _cg_node::change_to(_cg_node *oldnode, _cg_node *newnode) {
    if (!oldnode){
        throw nullException("Attempting to change a null target.");
    }
    if (!newnode){
        __glibc_macro_warning("Attempting to change a node into a null node.");
    }
    _cg_node* parent = oldnode->_parent;
    size_t index = oldnode->find_in_parent();
    parent->set_child(index, newnode);
    if (newnode)    newnode->_parent = parent;
}

void _cg_node::_del_as_node(_cg_node *&node) {
    if (!node){
        return;
    }
    for (auto & _child : node->_childs){
        _child->set_parent(nullptr);
    }
    delete node;
    node = nullptr;
}

void _cg_node::_del_as_root(_cg_node *&node) {
    if (!node){
        return;
    }
    _del_as_root_recur(node);
    delete node;
    node = nullptr;
}

void _cg_node::_del_as_root_recur(_cg_node *&node) {
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

void _cg_node::_throw_away(_cg_node *node) {
    if (!node){
        return;
    }
    _node_bin.push_back(node);
}

void _cg_node::_clear_bin() {
    for (auto & i : _node_bin){
        _del_as_node(i);
    }
    _node_bin.clear();
}

void _cg_node::_retrieve_bin() {
    while (!_node_bin.empty()){
        _node_bin.pop_back();
    }
}

_cg_node::~_cg_node() {
    delete _result;
}

bool _cg_node::is_num() {
    return false;
}

