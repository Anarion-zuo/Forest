//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST__EXP_NODE_H
#define CPPFOREST__EXP_NODE_H


#include "../_single_node.h"

class _exp_node : public _single_node {
public:
    _exp_node(_cg_node* parent, _cg_node* child);
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__EXP_NODE_H
