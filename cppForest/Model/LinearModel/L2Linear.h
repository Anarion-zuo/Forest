//
// Created by anarion on 2019/8/6.
//

#ifndef CPPFOREST_L2LINEAR_H
#define CPPFOREST_L2LINEAR_H

#include "../../cg/_cg.h"
#include "../../Data/FinalData.h"
#include "../../cgNode/_var.h"
#include "../../cgNode/singleNodes/number/_const_node.h"
#include "../../cgNode/singleNodes/number/_var_node.h"

class L2Linear {
protected:
    const FinalData& _X,& _y;
    size_t _dim;
    std::vector<_var*> _weights, _inputs_X;
    std::vector<_var_node*> _gradterms;
    _const_node* _inputs_negy;
    _cg_node* _node;

public:
    explicit L2Linear(const FinalData &X, const FinalData &negy);

    virtual void sgd_fit();
    virtual void gd_fit();
};


#endif //CPPFOREST_L2LINEAR_H
