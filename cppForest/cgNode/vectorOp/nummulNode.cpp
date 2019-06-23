//
// Created by anarion on 6/23/19.
//

#include "nummulNode.h"
#include "../singleNodes/number/constNode.h"
#include "../vectors/vecNode.h"
#include "../../MyException/VectorException/nummulException/nummulTypeException.h"

nummulNode::nummulNode(cgNode *parent, cgNode *left, cgNode *right) : cgNode(parent, {left, right}), _left(_childs[0]), _right(_childs[1]) {}

cgNode *nummulNode::clone(cgNode *parent) {
    std::vector<cgNode*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new nummulNode(parent, vec[0], vec[1]);
    p->set_childs_parents();
    return p;
}

void nummulNode::compute() {
    _left->compute();
    _right->compute();

    if (_left->get_result()->is_const()){
        double c = _left->get_result()->get_val();
        if (!_result){
            _result = new vecNode(this, std::vector<cgNode*>(_right->number_child(), nullptr));
        }
        for (size_t i = 0; i < _right->number_child(); ++i){
            _result->set_child(i, new constNode(_result, c * _right->get_child(i)->get_result()->get_val()));
        }
    } else if (_right->get_result()->is_const()){
        double c = _right->get_result()->get_val();
        if (!_result){
            _result = new vecNode(this, std::vector<cgNode*>(_left->number_child(), nullptr));
        }
        for (size_t i = 0; i < _left->number_child(); ++i){
            _result->set_child(i, new constNode(_result, c * _left->get_child(i)->get_result()->get_val()));
        }
    } else{
        throw nummulTypeException(this);
    }
}

void nummulNode::diff() {

}

void nummulNode::trim() {

}
