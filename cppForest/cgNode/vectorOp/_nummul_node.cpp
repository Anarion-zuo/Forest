//
// Created by anarion on 6/23/19.
//

#include "_nummul_node.h"
#include "../singleNodes/number/_const_node.h"
#include "../vectors/_vec_node.h"
#include "../../MyException/VectorException/nummulException/nummulTypeException.h"
#include "_vadd_node.h"

_nummul_node::_nummul_node(_cg_node *parent, _cg_node *left, _cg_node *right) : _cg_node(parent, {left, right}), _left(_childs[0]), _right(_childs[1]) {}

_cg_node *_nummul_node::clone(_cg_node *parent) {
    std::vector<_cg_node*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new _nummul_node(parent, vec[0], vec[1]);
    p->set_childs_parents();
    return p;
}

void _nummul_node::compute() {
    _left->compute();
    _right->compute();

    if (_left->get_result()->is_const()){
        double c = _left->get_result()->get_val();
        if (!_result){
            _result = new _vec_node(this, std::vector<_cg_node*>(_right->number_child(), nullptr));
        }
        for (size_t i = 0; i < _right->number_child(); ++i){
            _result->set_child(i, new _const_node(_result, c * _right->get_child(i)->get_result()->get_val()));
        }
    } else if (_right->get_result()->is_const()){
        double c = _right->get_result()->get_val();
        if (!_result){
            _result = new _vec_node(this, std::vector<_cg_node*>(_left->number_child(), nullptr));
        }
        for (size_t i = 0; i < _left->number_child(); ++i){
            _result->set_child(i, new _const_node(_result, c * _left->get_child(i)->get_result()->get_val()));
        }
    } else{
        throw nummulTypeException(this);
    }
}

void _nummul_node::diff() {
    auto left = this;
    auto right = clone(nullptr);
    auto ret = new _vadd_node(nullptr, left, right);
    ret->set_childs_parents();
    left->_left->diff();
    right->get_child(1)->diff();
    change_to(this, ret);
}

void _nummul_node::trim() {

}
