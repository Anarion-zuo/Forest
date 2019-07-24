//
// Created by anarion on 7/12/19.
//

#include "polyNode.h"
#include "../number/constNode.h"

#include <utility>

polyNode::polyNode(cgNode *parent, cgNode *child, std::vector< double> coeffs) : singleNode(parent, child), _coeffs(std::move(coeffs)) {}

cgNode *polyNode::clone(cgNode *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new polyNode(parent, child, _coeffs);
    p->set_childs_parents();
    return p;
}

void polyNode::compute() {
    _child->compute();
    double x = _child->get_result()->get_val();

    if (_coeffs.size() == 1){
        if (!_result){
            _result = new constNode(this, _coeffs[0]);
        } else {
            _result->set_val(_coeffs[0]);
        }
        return;
    }

    double cur = *(_coeffs.end() - 1);
    for (size_t i = _coeffs.size() - 2; i >= 0; --i){
        cur = x * cur + _coeffs[i];
    }
    if (!_result){
        _result = new constNode(this, cur);
    } else {
        _result->set_val(cur);
    }
}

void polyNode::diff() {
    _child->diff();
    std::vector<double> ret(_coeffs.size() - 1);
    for (size_t i = 0; i < ret.size(); ++i){
        size_t j = i + 1;
        ret[i] = _coeffs[j] * j;
    }
    _coeffs = ret;
}

void polyNode::trim() {

}
