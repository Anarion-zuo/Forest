//
// Created by anarion on 2019/7/18.
//

#ifndef CPPFOREST__COS_NODE_H
#define CPPFOREST__COS_NODE_H


#include "../../_single_node.h"

class _cos_node : public _single_node {
public:
    _cos_node(_cg_node* parent, _cg_node* child);
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__COS_NODE_H
