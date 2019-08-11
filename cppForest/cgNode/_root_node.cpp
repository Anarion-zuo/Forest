//
// Created by anarion on 7/7/19.
//

#include "_root_node.h"

_root_node::_root_node(_cg_node *child) : _cg_node(nullptr, {child}), _child(_childs[0]) {}

_cg_node *_root_node::clone(_cg_node *parent) {
    auto node = _child->clone(this);
    return new _root_node(node);
}

void _root_node::compute() {
    _child->compute();
    _val = _child->get_val();
}

void _root_node::diff() {
    _child->diff();
}

void _root_node::trim() {

}
