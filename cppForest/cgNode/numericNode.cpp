//
// Created by a on 2019/5/7.
//

#include "numericNode.h"
#include <cmath>

numericNode::numericNode(numericNode *parent, bool lr, numericNode *left, numericNode *right, double val)
: _parent(parent), _lr(lr), _left(left), _right(right), _val(val) {}

bool numericNode::num_equals(double n1, double n2) {
   double d = n1 - n2;
   if (d < 0){d = -d;}
   return d < std::numeric_limits<double>::epsilon() * 16;
}

bool numericNode::is_n_node(double n) {
    return false;
}

bool numericNode::is_var() {
    return false;
}

bool numericNode::is_const() {
    return false;
}

numericNode *numericNode::change_this(numericNode *node) {
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

void numericNode::change_left(numericNode* node){
    Garbage_Bin::push(_left);
    _left = node;
    node->_parent = this;
    node->_lr = false;
}

void numericNode::change_right(numericNode* node){
    Garbage_Bin::push(_left);
    _right = node;
    node->_parent = this;
    node->_lr = true;
}

void numericNode::set_var(double val) {
    _val = val;
}

double numericNode::get_val() {
    return _val;
}

void numericNode::set_parent(numericNode *node) {
    _parent = node;
}

numericNode *numericNode::get_parent() {
    return _parent;
}

void numericNode::set_lr(bool lr) {
    _lr = lr;
}

bool numericNode::get_lr() {
    return _lr;
}

numericNode *numericNode::get_left() {
    return _left;
}

numericNode *numericNode::get_right() {
    return _right;
}

void numericNode::del_node(numericNode*& node){
    node->del();
    if (!node->is_var()) {
        delete node;
        node = nullptr;
    }
}

void numericNode::del() {
    _left->del();
    _right->del();
    delete _left;
    delete _right;
}

std::vector<var*> numericNode::find_vars(numericNode* node) {
    std::vector<var*> res;
    _find_vars_recur(node, res);
    return res;
}

void numericNode::_find_vars_recur(numericNode* node, std::vector<var*>& v) {
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

numericNode *numericNode::_change_const(numericNode *node, double n) {
    return node->change_this(new constNode(node->_parent, node->_lr, n));
}

numericNode *numericNode::_change_if_both_const(numericNode *node) {
    if (node->_left->is_const() && node->_right->is_const()){
        Garbage_Bin::push(node->_left);
        Garbage_Bin::push(node->_right);
        return node->change_this(new constNode(node->_parent, node->_lr, node->_compute(node->_left->_val, node->_right->_val)));
    }
    return node;
}

double numericNode::compute() {
    _val = _compute(_left->compute(), _right->compute());
    return _val;
}

var *numericNode::get_var() {
    return nullptr;
}

numericNode *numericNode::sum(const std::vector<numericNode*> &nodes) {
    if (nodes.empty()){
        return nullptr;
    }
    if (nodes.size() == 1){
        return nodes[0];
    }
    std::vector<numericNode*> adds(nodes.size() / 2, nullptr);
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

bool numericNode::is_vector() {
    return false;
}


