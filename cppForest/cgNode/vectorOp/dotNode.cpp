//
// Created by anarion on 6/18/19.
//

#include "dotNode.h"
#include "../../MyException/VectorException/dotExceptions/vecSizeException.h"
#include "../../MyException/VectorException/dotExceptions/vecTypeException.h"
#include "../singleNodes/number/constNode.h"
#include "vaddNode.h"


dotNode::dotNode(cgNode *parent, cgNode *left, cgNode *right) noexcept(false) : cgNode(parent, {left, right}) {
    if (left && right){
        if (left->number_child() != right->number_child()){
            throw vecSizeException(this);
        }
    }

}

cgNode *dotNode::clone(cgNode *parent) {
    std::vector<cgNode*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new dotNode(parent, vec[0], vec[1]);
    p->set_childs_parents();
    return p;
}

void dotNode::compute() {
    _left->compute();
    _right->compute();
    for (auto &i : _left->get_childs()){
        if (!i->get_result()->is_single_val()){
            throw vecTypeException(_left, _left->find_in_parent());
        }
    }
    for (auto &i : _right->get_childs()){
        if (!i->get_result()->is_single_val()){
            throw vecTypeException(_right, _right->find_in_parent());
        }
    }

    double res = 0;
    for (size_t i = 0; i < _left->number_child(); ++i){
        res += _left->get_result()->get_child(i)->get_val() * _right->get_result()->get_child(i)->get_val();
    }

    if (!_result){
        _result = new constNode(_parent, res);
        return;
    }
    _result->set_val(res);

}

size_t dotNode::get_num_left() {
    return _childs[0]->number_child();
}

size_t dotNode::get_num_right() {
    return _childs[1]->number_child();
}

void dotNode::diff() {
    auto left = this;
    auto right = clone(nullptr);
    auto ret = new vaddNode(nullptr, left, right);
    ret->set_childs_parents();
    left->_left->diff();
    right->get_child(1)->diff();
    change_to(this, ret);
}

void dotNode::trim() {

}
