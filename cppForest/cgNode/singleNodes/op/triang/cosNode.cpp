//
// Created by anarion on 2019/7/18.
//

#include <ctgmath>
#include "cosNode.h"
#include "sinNode.h"
#include "../../number/constNode.h"
#include "../../../multiop/mulNode.h"

cosNode::cosNode(cgNode *parent, cgNode *child) : singleNode(parent, child) {}

cgNode *cosNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new cosNode(parent, child);
    p->set_childs_parents();
    return p;
}

void cosNode::compute() {
    _child->compute();
    if (!_result)   _result = new constNode(this, 0);
    _result->set_val(cos(_child->get_result()->get_val()));
}

void cosNode::diff() {
    auto coef = _child->clone(nullptr);
    auto ret = new mulNode(nullptr, new mulNode(nullptr, new constNode(nullptr, -1), coef), new sinNode(nullptr, _child));
    ret->set_childs_parents();
    ret->get_child(0)->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void cosNode::trim() {

}
