//
// Created by anarion on 6/18/19.
//

#include <tgmath.h>
#include "lnNode.h"
#include "../number/constNode.h"
#include "../../../MyException/VectorException/singleException/singleException.h"

lnNode::lnNode(cgNode *parent, cgNode *child) : singleNode(parent, child) {
    if (child->number_child() != 1){
        throw singleException(this);
    }
}

cgNode *lnNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new lnNode(parent, child);
    p->set_childs_parents();
    return p;
}

void lnNode::compute() {
    _child->compute();
    _result = new constNode(this, log(_child->get_result()->get_val()));
}
