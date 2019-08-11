//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST__DOT_NODE_H
#define CPPFOREST__DOT_NODE_H


#include "../_cg_node.h"
#include "../../MyException/VectorException/dotExceptions/vecSizeException.h"
#include "../multiop/_mul_node.h"
#include "../multiop/_sum_node.h"

class _dot_node : public _sum_node {
protected:
    _cg_node*& _left = _childs[0];
    _cg_node*& _right = _childs[1];
private:
public:
    _dot_node(_cg_node *parent, std::vector<_cg_node *>& left, std::vector<_cg_node *>& right) noexcept(false);
    virtual ~_dot_node() = default;
};


#endif //CPPFOREST__DOT_NODE_H
