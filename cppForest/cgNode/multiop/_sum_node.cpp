//
// Created by anarion on 6/17/19.
//

#include "_sum_node.h"
#include "../vectors/_vec_node.h"
#include "../singleNodes/number/_const_node.h"
#include "../../MyException/VectorException/singleException/singleException.h"


_sum_node::_sum_node(_cg_node *parent, const std::vector<_cg_node *> &childs) : _vec_node(parent, childs) {}

_cg_node *_sum_node::clone(_cg_node* parent) {
    std::vector<_cg_node*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new _sum_node(parent, vec);
    p->set_childs_parents();
    return p;
}

void _sum_node::diff() {
    for (auto child : _childs) {
        child->diff();
    }
}

void _sum_node::compute() {
    for (size_t i = 0; i < _childs.size(); ++i){
        _childs[i]->compute();
    }
    if (!_result){
        _result = new _const_node(this, 0);
    }
    double ret = 0;
    for (auto child : _childs){
        auto pr =  child->get_result();
        if (!pr->is_const()){
            throw singleException(this);
        }
        ret += child->get_result()->get_val();
    }
    _result->set_val(ret);
}
