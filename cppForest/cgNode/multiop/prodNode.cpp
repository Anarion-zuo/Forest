//
// Created by anarion on 2019/7/29.
//

#include "prodNode.h"
#include "mulNode.h"
#include "../singleNodes/number/constNode.h"
#include "../../MyException/VectorException/singleException/singleException.h"

prodNode::prodNode(cgNode *parent, const std::vector<cgNode *> &childs) : vecNode(parent, childs) {}

cgNode *prodNode::clone(cgNode *parent) {
    std::vector<cgNode*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new prodNode(parent, vec);
    p->set_childs_parents();
    return p;
}

std::vector<cgNode*>&& prodNode::_build_prod_recur(std::vector<cgNode *> &list) {
    size_t len = list.size(), newlen;
    if (len == 1){
        return move(list);
    }
    if (len % 2){
        newlen = len / 2 + 1;
    } else {
        newlen = len / 2;
    }
    std::vector<cgNode*> newlist(newlen);
    for (size_t i = 0; i < newlen; ++i){
        size_t j = 2 * i;
        newlist[i] = new mulNode(nullptr, list[j], list[j + 1]);
        newlist[i]->set_childs_parents();
    }
    return _build_prod_recur(newlist);
}

void prodNode::compute() {
    for (auto child : _childs){
        child->compute();
    }
    if (!_result){
        _result = new constNode(this, 0);
    }
    double ret = 1;
    for (auto child : _childs){
        auto pr =  child->get_result();
        if (!pr->is_const()){
            throw singleException(this);
        }
        ret *= child->get_result()->get_val();
    }
    _result->set_val(ret);
}

void prodNode::diff() {
    if (!_tree_form){
        _tree_form = _build_prod_recur(_childs)[0];
    }
    _tree_form->diff();
    change_to(this, _tree_form);
}
