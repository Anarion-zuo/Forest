//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST__POW_NODE_H
#define CPPFOREST__POW_NODE_H


#include "../_single_node.h"

class _pow_node : public _single_node {
protected:
    double _pow;
public:
    _pow_node(_cg_node* parent, _cg_node* child, double pow);
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__POW_NODE_H
