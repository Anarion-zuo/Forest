//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST__MUL_NODE_H
#define CPPFOREST__MUL_NODE_H

#include "../vectorOp/_dot_node.h"

class _mul_node : public _cg_node {
protected:
    _cg_node*& _left;
    _cg_node*& _right;
public:
    _mul_node(_cg_node *parent, _cg_node* left, _cg_node* right);
    ~_mul_node() override = default;
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__MUL_NODE_H
