//
// Created by a on 2019/5/14.
//

#include "cg.h"

cg::cg(cgNode *root) : _root(root) {}

cg::~cg() {
    cgNode::del_node(_root);
}

