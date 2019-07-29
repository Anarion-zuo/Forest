//
// Created by anarion on 7/7/19.
//

#include "mulNode.h"
#include "../singleNodes/number/constNode.h"
#include "../../MyException/VectorException/singleException/singleException.h"
#include "../vectors/vecNode.h"
#include "sumNode.h"

mulNode::mulNode(cgNode *parent, cgNode* left, cgNode* right) : cgNode(parent, {left, right}), _left(_childs[0]), _right(_childs[1]) {
    set_childs_parents();
}

cgNode *mulNode::clone(cgNode *parent) {
    auto p =  new mulNode(parent, _left, _right);
    for (auto & i : p->_childs){
        i = i->clone(p);
    }
    return p;
}

void mulNode::compute() {
    _left->compute();
    _right->compute();

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

void mulNode::diff() {
    auto cl = clone(nullptr);
    auto sum = new sumNode(nullptr, {this, cl});
    sum->set_childs_parents();
    _left->diff();
    cl->get_child(1)->diff();
    change_to(this, sum);
}

void mulNode::trim() {

}

