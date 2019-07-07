//
// Created by anarion on 7/7/19.
//

#include "dcg.h"

dcg::dcg(cgNode *root) : cg(root) {}

dcg::dcg(cg* graph) : cg(graph){
    auto node = _root->get_child(0);
    node->diff();
}

cg *dcg::clone() {
    auto node = _root->get_child(0)->clone(nullptr);
    return new dcg(node);
}

void dcg::compute(var *x) {
    auto it = var::set_dvar(x);
    cg::compute();
    var::clear_dvar(it);
}
