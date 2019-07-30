//
// Created by anarion on 7/7/19.
//

#include "_cg.h"
#include "../cgNode/_root_node.h"
#include "_dcg.h"

_cg::_cg(_cg_node *root) : _root(new _root_node(root)) {
    _root->set_childs_parents();
}

_cg::~_cg() {
    _cg_node::_del_as_root(_root->_childs[0]);
}

_cg *_cg::clone() {
    auto node = _root->get_child(0)->clone(nullptr);
    return new _cg(node);
}

void _cg::compute() {
    _root->compute();
}

_cg_node *_cg::get_result() {
    return _root->get_result();
}

_cg::_cg(_cg *graph) : _root(graph->_root->clone(nullptr)) {
    _root->set_childs_parents();
}

