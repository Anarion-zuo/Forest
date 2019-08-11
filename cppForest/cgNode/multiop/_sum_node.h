//
// Created by anarion on 6/17/19.
//

#ifndef CPPFOREST__SUM_NODE_H
#define CPPFOREST__SUM_NODE_H


#include "../_cg_node.h"

class _sum_node : public _cg_node {
private:

public:
    _sum_node(_cg_node* parent, const std::vector<_cg_node*>& childs);
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__SUM_NODE_H
