//
// Created by anarion on 6/17/19.
//

#ifndef CPPFOREST__SINGLE_NODE_H
#define CPPFOREST__SINGLE_NODE_H


#include "../_cg_node.h"

class _single_node : public _cg_node {
protected:
    _cg_node*& _child = _childs[0];
public:
    _single_node(_cg_node* parent, _cg_node* child);
    _single_node(_cg_node* parent, _cg_node* child, double val);
    virtual ~_single_node() = default;

    bool is_single_val() override ;
};


#endif //CPPFOREST__SINGLE_NODE_H
