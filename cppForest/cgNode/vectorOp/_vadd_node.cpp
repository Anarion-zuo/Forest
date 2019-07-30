//
// Created by anarion on 7/2/19.
//

#include "_vadd_node.h"
#include "../../MyException/VectorException/dotExceptions/vecSizeException.h"
#include "../../MyException/VectorException/dotExceptions/vecTypeException.h"
#include "../singleNodes/number/_const_node.h"
#include "../vectors/_vec_node.h"

_vadd_node::_vadd_node(_cg_node *parent, _cg_node *left, _cg_node *right) noexcept(false): _cg_node(parent, {left, right}) {
    if (left && right){
        if (left->number_child() != right->number_child()){
            throw vecSizeException(this);
        }
    }

}

_cg_node *_vadd_node::clone(_cg_node *parent) {
    std::vector<_cg_node*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new _vadd_node(parent, vec[0], vec[1]);
    p->set_childs_parents();
    return p;
}

void _vadd_node::compute() {
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

    std::vector<_cg_node*> res(_left->number_child(), nullptr);
    for (size_t i = 0; i < _left->number_child(); ++i){
        res[i] = new _const_node(nullptr, _left->get_result()->get_child(i)->get_val() + _right->get_result()->get_child(i)->get_val());
    }

    if (!_result){
        _result = new _vec_node(_parent, res);
        return;
    }
    _result->get_childs() = res;
}

void _vadd_node::diff() {
    _left->diff();
    _right->diff();
}

void _vadd_node::trim() {

}

_cg_node *_vadd_node::get_left() {
    return _left;
}

_cg_node *_vadd_node::get_right() {
    return _right;
}

