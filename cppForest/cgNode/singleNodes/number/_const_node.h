//Expect a vector node with a single component.
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST__CONST_NODE_H
#define CPPFOREST__CONST_NODE_H


#include "../_single_node.h"

class _const_node : public _single_node {
private:
public:
    _const_node(_cg_node* parent, double val);
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;

    bool is_const() override ;
    bool is_num() override ;
};


#endif //CPPFOREST__CONST_NODE_H
