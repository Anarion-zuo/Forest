//
// Created by anarion on 6/18/19.
//

#include "_vec_node.h"

_vec_node::_vec_node(_cg_node *parent, const std::vector<_cg_node *> &childs) : _cg_node(parent, childs) {}

_cg_node *_vec_node::clone(_cg_node *parent) {
    std::vector<_cg_node*> vec(_childs);
    auto p =  new _vec_node(parent, vec);
    for (auto & i : vec){
        i = i->clone(p);
    }
    return p;
}

void _vec_node::compute() {
    if (!_result){
        _result = new _vec_node(this, std::vector<_cg_node*>(_childs));
    }
    for (size_t i = 0; i < number_child(); ++i){
        _childs[i]->compute();
        _result->set_child(i, _childs[i]->get_result());
    }

}

void _vec_node::diff() {
    for (auto &child : _childs) {
        child->diff();
    }
}

void _vec_node::trim() {

}
