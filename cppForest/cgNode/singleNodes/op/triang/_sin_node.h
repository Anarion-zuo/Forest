//
// Created by anarion on 2019/7/18.
//

#ifndef CPPFOREST__SIN_NODE_H
#define CPPFOREST__SIN_NODE_H


#include "../../_single_node.h"

class _sin_node : public _single_node {
public:
    _sin_node(_cg_node* parent, _cg_node* child);
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__SIN_NODE_H
