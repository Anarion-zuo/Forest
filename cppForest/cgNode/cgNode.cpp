//
// Created by a on 2019/5/7.
//

#include "cgNode.h"
#include <cmath>

cgNode::cgNode(cgNode *parent, bool lr, cgNode *left, cgNode *right, double val)
: _parent(parent), _lr(lr), _left(left), _right(right), _val(val) {}

bool cgNode::num_equals(double n1, double n2) {
   double d = n1 - n2;
   if (d < 0){d = -d;}
   return d < std::numeric_limits<double>::epsilon() * 16;
}

bool cgNode::is_n_node(double n) {
    return false;
}

bool cgNode::is_var() {
    return false;
}

bool cgNode::is_const() {
    return false;
}

cgNode *cgNode::change_this(cgNode *node) {
    if (_lr){
        _parent->_right = node;
    }else{
        _parent->_left = node;
    }
    node->_lr = _lr;
    node->_parent = _parent;
    Garbage_Bin::push(this);
    return node;
}

void cgNode::change_left(cgNode* node){
    Garbage_Bin::push(_left);
    _left = node;
    node->_parent = this;
    node->_lr = false;
}

void cgNode::change_right(cgNode* node){
    Garbage_Bin::push(_left);
    _right = node;
    node->_parent = this;
    node->_lr = true;
}

void cgNode::set_var(double val) {
    _val = val;
}

double cgNode::get_val() {
    return _val;
}

void cgNode::set_parent(cgNode *node) {
    _parent = node;
}

cgNode *cgNode::get_parent() {
    return _parent;
}

void cgNode::set_lr(bool lr) {
    _lr = lr;
}

bool cgNode::get_lr() {
    return _lr;
}

cgNode *cgNode::get_left() {
    return _left;
}

cgNode *cgNode::get_right() {
    return _right;
}

void cgNode::del_node(cgNode*& node){
    node->del();
    if (!node->is_var()) {
        delete node;
        node = nullptr;
    }
}

void cgNode::del() {
    _left->del();
    _right->del();
    if (!_left->is_var())    delete _left;
    if (!_right->is_var())  delete _right;
}

std::vector<var*> cgNode::find_vars(cgNode* node) {
    std::vector<var*> res;
    _find_vars_recur(node, res);
    return res;
}

void cgNode::_find_vars_recur(cgNode* node, std::vector<var*>& v) {
    if (!node){
        return;
    }
    if (node->is_var()){
        v.push_back(node->get_var());
        return;
    }
    if (node->is_const()){
        return;
    }
    _find_vars_recur(node->_left, v);
    _find_vars_recur(node->_right, v);
}

cgNode *cgNode::_change_const(cgNode *node, double n) {
    return node->change_this(new constNode(node->_parent, node->_lr, n));
}

cgNode *cgNode::_change_if_both_const(cgNode *node) {
    if (node->_left->is_const() && node->_right->is_const()){
        Garbage_Bin::push(node->_left);
        Garbage_Bin::push(node->_right);
        return node->change_this(new constNode(node->_parent, node->_lr, node->_compute(node->_left->_val, node->_right->_val)));
    }
    return node;
}

double cgNode::compute() {
    _val = _compute(_left->compute(), _right->compute());
    return _val;
}

var *cgNode::get_var() {
    return nullptr;
}

cgNode *cgNode::sum(const std::vector<cgNode*> &nodes) {
    if (nodes.empty()){
        return nullptr;
    }
    if (nodes.size() == 1){
        return nodes[0];
    }
    std::vector<cgNode*> adds(nodes.size() / 2, nullptr);
    for (size_t i = 0; i < adds.size(); ++i){
        auto an = new addNode(nullptr, false, nodes[2 * i], nodes[2 * i + 1]);
        an->_left->set_parent(an);
        an->_right->set_parent(an);
        an->_left->set_lr(false);
        an->_right->set_lr(true);
        adds[i] = an;
    }
    if (nodes.size() % 2){
        adds.push_back(nodes[nodes.size() - 1]);
    }
    return sum(adds);
}


