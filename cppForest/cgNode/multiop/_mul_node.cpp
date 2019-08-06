//
// Created by anarion on 7/7/19.
//

#include "_mul_node.h"
#include "../singleNodes/number/_const_node.h"
#include "../../MyException/VectorException/singleException/singleException.h"
#include "../vectors/_vec_node.h"
#include "_sum_node.h"

_mul_node::_mul_node(_cg_node *parent, _cg_node* left, _cg_node* right) : _cg_node(parent, {left, right}), _left(_childs[0]), _right(_childs[1]) {
}

_cg_node *_mul_node::clone(_cg_node *parent) {
    auto p =  new _mul_node(parent, _left, _right);
    for (auto & i : p->_childs){
        i = i->clone(p);
    }
    return p;
}

void _mul_node::compute() {
    _left->compute();
    _right->compute();

    if (!_result){
        _result = new _const_node(this, 0);
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

void _mul_node::diff() {
    auto cl = clone(nullptr);
    auto sum = new _sum_node(nullptr, {this, cl});
    sum->set_childs_parents();
    _left->diff();
    cl->get_child(1)->diff();
    change_to(this, sum);
}

void _mul_node::trim() {

}

