//
// Created by anarion on 6/17/19.
//

#include "sumNode.h"
#include "../vectors/vecNode.h"
#include "../singleNodes/number/constNode.h"
#include "../../MyException/VectorException/singleException/singleException.h"


sumNode::sumNode(cgNode *parent, const std::vector<cgNode *> &childs) : vecNode(parent, childs) {}

cgNode *sumNode::clone(cgNode* parent) {
    std::vector<cgNode*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new sumNode(parent, vec);
    p->set_childs_parents();
    return p;
}

void sumNode::diff() {
    for (auto child : _childs) {
        child->diff();
    }
}

void sumNode::compute() {
    for (auto child : _childs){
        child->compute();
    }
    if (!_result){
        _result = new constNode(this, 0);
    }
    double ret = 0;
    for (auto child : _childs){
        auto pr =  child->get_result();
        if (!pr->is_const()){
            throw singleException(this);
        }
        ret += child->get_result()->get_val();
    }
    _result->set_val(ret);
}
