//
// Created by anarion on 7/2/19.
//

#include "vaddNode.h"
#include "../../MyException/VectorException/dotExceptions/vecSizeException.h"
#include "../../MyException/VectorException/dotExceptions/vecTypeException.h"
#include "../singleNodes/number/constNode.h"
#include "../vectors/vecNode.h"

vaddNode::vaddNode(cgNode *parent, cgNode *left, cgNode *right) noexcept(false): cgNode(parent, {left, right}) {
    if (left && right){
        if (left->number_child() != right->number_child()){
            throw vecSizeException(this);
        }
    }

}

cgNode *vaddNode::clone(cgNode *parent) {
    std::vector<cgNode*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new vaddNode(parent, vec[0], vec[1]);
    p->set_childs_parents();
    return p;
}

void vaddNode::compute() {
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

    std::vector<cgNode*> res(_left->number_child(), nullptr);
    for (size_t i = 0; i < _left->number_child(); ++i){
        res[i] = new constNode(nullptr, _left->get_result()->get_child(i)->get_val() + _right->get_result()->get_child(i)->get_val());
    }

    if (!_result){
        _result = new vecNode(_parent, res);
        return;
    }
    _result->get_childs() = res;
}

void vaddNode::diff() {
    _left->diff();
    _right->diff();
}

void vaddNode::trim() {

}

cgNode *vaddNode::get_left() {
    return _left;
}

cgNode *vaddNode::get_right() {
    return _right;
}

