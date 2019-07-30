//
// Created by anarion on 6/18/19.
//

#include "_dot_node.h"
#include "../../MyException/VectorException/dotExceptions/vecSizeException.h"
#include "../../MyException/VectorException/dotExceptions/vecTypeException.h"
#include "../singleNodes/number/_const_node.h"
#include "_vadd_node.h"


_dot_node::_dot_node(_cg_node *parent, _cg_node *left, _cg_node *right) noexcept(false) : _cg_node(parent, {left, right}) {
    if (left && right){
        if (left->number_child() != right->number_child()){
            throw vecSizeException(this);
        }
    }

}

_cg_node *_dot_node::clone(_cg_node *parent) {
    std::vector<_cg_node*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new _dot_node(parent, vec[0], vec[1]);
    p->set_childs_parents();
    return p;
}

void _dot_node::compute() {
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
        _result = new _const_node(_parent, res);
        return;
    }
    _result->set_val(res);

}

size_t _dot_node::get_num_left() {
    return _childs[0]->number_child();
}

size_t _dot_node::get_num_right() {
    return _childs[1]->number_child();
}

void _dot_node::diff() {
    auto left = this;
    auto right = clone(nullptr);
    auto ret = new _vadd_node(nullptr, left, right);
    ret->set_childs_parents();
    left->_left->diff();
    right->get_child(1)->diff();
    change_to(this, ret);
}

void _dot_node::trim() {

}
