//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST__ROOT_NODE_H
#define CPPFOREST__ROOT_NODE_H


#include "_cg_node.h"

class _root_node : public _cg_node {
    _cg_node* &_child;
public:
    explicit _root_node(_cg_node* child);
    virtual ~_root_node() = default;
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__ROOT_NODE_H
