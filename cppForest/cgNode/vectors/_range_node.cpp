//
// Created by anarion on 2019/8/5.
//

#include "_range_node.h"
#include "../../MyException/VectorException/singleException/singleException.h"
#include "../singleNodes/number/_const_node.h"

#include <utility>

_range_node::_range_node(_cg_node *parent, _cg_node *child, std::vector<double> threash, std::vector<_cg_node *> ops) : _cg_node(parent, {child}), _threash(std::move(threash)), _ops(std::move(ops)), _child(_childs[0]) {
    for (auto op : ops){
        op->set_child(0, _child);
    }
}

_cg_node *_range_node::clone(_cg_node *parent) {
    auto p = new _range_node(parent, _child->clone(nullptr), std::vector<double>(_threash), std::vector<_cg_node*>(_ops));
    p->set_childs_parents();
    return p;
}

void _range_node::compute() {
    _child->compute();
    auto result = _child->get_result();
    if (result->is_const()){
        throw singleException(this);
    }
    double res = result->get_val();
    size_t index = choose_op(res, _threash);
    _cg_node* op = _ops[index];
    op->compute();
    _result = op->get_result();
}

double _range_node::choose_op(double res, const std::vector<double>& threash) {
    for (size_t i = 0; i < threash.size(); ++i){
        if (res < threash[i]){
            return i;
        }
    }
    return threash.size();
}

void _range_node::diff() {
    auto tc = new _const_node(nullptr, 0);
    for (auto op : _ops){
        op->set_child(0, tc);
        op->diff();
    }
    _child->diff();
    for (auto op : _ops){
        op->set_child(0, _child);
    }
}

void _range_node::trim() {

}



