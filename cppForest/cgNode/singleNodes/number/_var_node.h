//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST__VAR_NODE_H
#define CPPFOREST__VAR_NODE_H


#include "../../_cg_node.h"
#include "../../_var.h"
#include "../_single_node.h"

class _var_node : public _single_node {
private:
    _var* _x;
public:
    _var_node(_cg_node* parent, _var* pvar);
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;

    double get_val() override ;
    void set_val(double val) override ;

    bool is_num() override ;
};


#endif //CPPFOREST__VAR_NODE_H
