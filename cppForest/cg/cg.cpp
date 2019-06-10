//
// Created by a on 2019/5/14.
//

#include "cg.h"

cg::cg(cgNode *root) : _root(root), _vars(cgNode::find_vars(root)) {}

cg::~cg() {
    cgNode::del_node(_root);
}

cg::cg(cg *graph) : _root(graph->_root), _vars(graph->_vars) {}

