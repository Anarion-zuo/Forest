//
// Created by anarion on 7/7/19.
//

#include "mulNode.h"
#include "../singleNodes/number/constNode.h"
#include "../../MyException/VectorException/singleException/singleException.h"
#include "../vectors/vecNode.h"

mulNode::mulNode(cgNode *parent, cgNode* left, cgNode* right) : dotNode(parent, new vecNode(nullptr, {left}), new vecNode(nullptr, {right})) {
    set_childs_parents();
}

cgNode *mulNode::clone(cgNode *parent) {
    auto p =  new mulNode(parent, _left, _right);
    for (auto & i : p->_childs){
        i = i->clone(p);
    }
    return p;
}

