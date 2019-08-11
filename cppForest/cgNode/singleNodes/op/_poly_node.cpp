//
// Created by anarion on 7/12/19.
//

#include "_poly_node.h"
#include "../number/_const_node.h"

#include <utility>

_poly_node::_poly_node(_cg_node *parent, _cg_node *child, std::vector< double> coeffs) : _single_node(parent, child), _coeffs(std::move(coeffs)) {}

_cg_node *_poly_node::clone(_cg_node *parent) {
    auto child = _child->clone(nullptr);
    auto p =  new _poly_node(parent, child, _coeffs);
    p->set_childs_parents();
    return p;
}

void _poly_node::compute() {
    _child->compute();
    double x = _child->get_val();

    if (_coeffs.size() == 1){
        _val = _coeffs[0];
        return;
    }

    double cur = *(_coeffs.end() - 1);
    for (size_t i = _coeffs.size() - 2; i >= 0; --i){
        cur = x * cur + _coeffs[i];
    }
    _val = cur;
}

void _poly_node::diff() {
    _child->diff();
    std::vector<double> ret(_coeffs.size() - 1);
    for (size_t i = 0; i < ret.size(); ++i){
        size_t j = i + 1;
        ret[i] = _coeffs[j] * j;
    }
    _coeffs = ret;
}

void _poly_node::trim() {

}
