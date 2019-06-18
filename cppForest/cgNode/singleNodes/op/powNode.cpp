//
// Created by anarion on 6/18/19.
//

#include "powNode.h"

powNode::powNode(cgNode *parent, cgNode *child, double pow) : singleNode(parent, child), _pow(pow) {}

cgNode *powNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new powNode(parent, child, _pow);
    p->set_childs_parents();
    return p;
}

void powNode::compute() {
    _child->compute();

    for (auto &i : _left->get_childs()){
        if (!i->get_result()->is_single_val()){
            throw dotTypeException(_right, _right->index_parent());
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
