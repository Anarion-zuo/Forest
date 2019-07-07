//
// Created by anarion on 7/7/19.
//

#include "cg.h"
#include "../cgNode/rootNode.h"

cg::cg(cgNode *root) : _root(new rootNode(root)) {
    _root->set_childs_parents();
}

cg::~cg() {
    cgNode::_del_as_root(_root->_childs[0]);
}

cg *cg::clone() {
    auto node = _root->get_child(0)->clone(nullptr);
    return new cg(node);
}

void cg::compute() {
    _root->compute();
}

cgNode *cg::get_result() {
    return _root->get_result();
}

dcg *cg::diff() {
    auto node = _root->_childs[0]->clone(nullptr);
    node->diff();
    return new dcg(node);
}
