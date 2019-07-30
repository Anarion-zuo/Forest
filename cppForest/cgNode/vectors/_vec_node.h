//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST__VEC_NODE_H
#define CPPFOREST__VEC_NODE_H


#include "../_cg_node.h"

class _vec_node : public _cg_node {
public:
    _vec_node(_cg_node* parent, const std::vector<_cg_node*>& childs);
    virtual _cg_node* clone(_cg_node* parent) override ;

    virtual void compute() override ;
    virtual void diff() override ;
    virtual void trim() override ;
};


#endif //CPPFOREST__VEC_NODE_H
