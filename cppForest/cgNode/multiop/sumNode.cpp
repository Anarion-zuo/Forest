//
// Created by anarion on 6/17/19.
//

#include "sumNode.h"
#include "../vectors/vecNode.h"
#include "../singleNodes/number/constNode.h"


sumNode::sumNode(cgNode *parent, const std::vector<cgNode *> &childs) : dotNode(parent, nullptr, nullptr) {
    auto left = new vecNode(this, childs);
    auto right = new vecNode(this, std::vector<cgNode*>(childs.size(), new constNode(nullptr, 1)));
    right->set_childs_parents();
    _left = left;
    _right = right;
}

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
    for (auto &child : _childs) {
        child->diff();
    }
}
