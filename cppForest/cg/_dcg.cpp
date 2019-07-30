//
// Created by anarion on 7/7/19.
//

#include "_dcg.h"

_dcg::_dcg(_cg_node *root) : _cg(root) {}

_dcg::_dcg(_cg* graph) : _cg(graph){
    auto node = _root->get_child(0);
    node->diff();
}

_cg *_dcg::clone() {
    auto node = _root->get_child(0)->clone(nullptr);
    return new _dcg(node);
}

void _dcg::compute(_var *x) {
    auto it = _var::set_dvar(x);
    _cg::compute();
    _var::clear_dvar(it);
}

