//
// Created by anarion on 6/18/19.
//

#include "vecNode.h"

vecNode::vecNode(cgNode *parent, const std::vector<cgNode *> &childs) : cgNode(parent, childs) {}

cgNode *vecNode::clone(cgNode *parent) {
    std::vector<cgNode*> vec(_childs);
    auto p =  new vecNode(parent, vec);
    for (auto & i : vec){
        i = i->clone(p);
    }
    return p;
}

void vecNode::compute() {
    if (!_result){
        _result = new vecNode(this, std::vector<cgNode*>(_childs));
    }
    for (size_t i = 0; i < number_child(); ++i){
        _childs[i]->compute();
        _result->get_child(i) = _childs[i]->get_result();
    }

}

void vecNode::diff() {

}

void vecNode::trim() {

}
