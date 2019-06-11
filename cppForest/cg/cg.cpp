//
// Created by a on 2019/5/14.
//

#include "cg.h"

cg::cg(cgNode *root) : _root(root), _vars(cgNode::find_vars(root)) {
    _root->set_parent(_root);
}

cg::~cg() {
    cgNode::del_node(_root);
}

cg::cg(cg *graph) : _root(graph->_root), _vars(graph->_vars) {}


void cg::compute() {
    _root->compute();
}

cg *cg::clone() {
    return new cg(this);
}

double cg::latest_result() {
    return _root->get_val();
}

