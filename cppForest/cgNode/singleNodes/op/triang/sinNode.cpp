//
// Created by anarion on 2019/7/18.
//

#include <ctgmath>
#include "sinNode.h"
#include "../../number/constNode.h"
#include "../../../multiop/mulNode.h"
#include "cosNode.h"

sinNode::sinNode(cgNode *parent, cgNode *child) : singleNode(parent, child) {

}

cgNode *sinNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new sinNode(parent, child);
    p->set_childs_parents();
    return p;
}

void sinNode::compute() {
    _child->compute();
    if (!_result)   _result = new constNode(this, 0);
    _result->set_val(sin(_child->get_result()->get_val()));
}

void sinNode::diff() {
    auto coef = _child->clone(nullptr);
    auto ret = new mulNode(nullptr, coef, new cosNode(nullptr, _child));
    ret->set_childs_parents();
    coef->diff();
    change_to(this, ret);
}

void sinNode::trim() {

}
