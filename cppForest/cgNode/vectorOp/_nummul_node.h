//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST__NUMMUL_NODE_H
#define CPPFOREST__NUMMUL_NODE_H


#include "../_cg_node.h"

class _nummul_node : public _cg_node {
protected:
    _cg_node* &_left;
    _cg_node* &_right;
public:
    _nummul_node(_cg_node* parent, _cg_node* left, _cg_node* right); // the left node must be of single type
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__NUMMUL_NODE_H
