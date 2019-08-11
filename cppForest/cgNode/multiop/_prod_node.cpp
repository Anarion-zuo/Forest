//
// Created by anarion on 2019/7/29.
//

#include "_prod_node.h"
#include "_mul_node.h"
#include "../singleNodes/number/_const_node.h"
#include "../../MyException/VectorException/singleException/singleException.h"

_prod_node::_prod_node(_cg_node *parent, const std::vector<_cg_node *> &childs) : _cg_node(parent, childs) {}

_cg_node *_prod_node::clone(_cg_node *parent) {
    std::vector<_cg_node*> vec(_childs);
    for (auto & i : vec){
        i = i->clone(nullptr);
    }
    auto p =  new _prod_node(parent, vec);
    p->set_childs_parents();
    return p;
}

std::vector<_cg_node*>&& _prod_node::_build_prod_recur(std::vector<_cg_node *> &list) {
    size_t len = list.size(), newlen;
    if (len == 1){
        return move(list);
    }
    if (len % 2){
        newlen = len / 2 + 1;
    } else {
        newlen = len / 2;
    }
    std::vector<_cg_node*> newlist(newlen);
    for (size_t i = 0; i < newlen; ++i){
        size_t j = 2 * i;
        newlist[i] = new _mul_node(nullptr, list[j], list[j + 1]);
        newlist[i]->set_childs_parents();
    }
    return _build_prod_recur(newlist);
}

void _prod_node::compute() {
    for (auto child : _childs){
        child->compute();
    }
    double ret = 1;
    for (auto child : _childs){
        ret *= child->get_val();
    }
    _val = ret;
}

void _prod_node::diff() {
    if (!_tree_form){
        _tree_form = _build_prod_recur(_childs)[0];
    }
    _tree_form->diff();
    change_to(this, _tree_form);
}

void _prod_node::trim() {

}
