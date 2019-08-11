//
// Created by anarion on 6/18/19.
//

#include "_dot_node.h"
#include "../../MyException/VectorException/dotExceptions/vecSizeException.h"
#include "../../MyException/VectorException/dotExceptions/vecTypeException.h"
#include "../singleNodes/number/_const_node.h"


_dot_node::_dot_node(_cg_node *parent, std::vector<_cg_node *>& left, std::vector<_cg_node *>& right) noexcept(false) : _sum_node(parent, std::vector<_cg_node*>(left.size())) {
    if (left.size() != right.size()){
        throw vecSizeException(this);
    }
    for (size_t i = 0; i < _childs.size(); ++i){
        _childs[i] = new _mul_node(nullptr, left[i], right[i]);
    }
}
