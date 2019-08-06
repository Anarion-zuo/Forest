//
// Created by anarion on 2019/8/6.
//

#ifndef CPPFOREST_L2LINEAR_H
#define CPPFOREST_L2LINEAR_H

#include "../../cg/_cg.h"
#include "../../Data/DataFrame.h"
#include "../../cgNode/_var.h"
#include "../../cgNode/singleNodes/number/_const_node.h"
#include "../../cgNode/singleNodes/number/_var_node.h"

class L2Linear {
protected:
    const DataFrame& _X,& _y;
    size_t _dim;
    std::vector<_var*> _weights, _inputs_X;
    std::vector<_var_node*> _gradterms;
    _const_node* _inputs_negy;
    _cg_node* _node;

    void set_y(double n);
    void change_to_next_term();
public:
    explicit L2Linear(const DataFrame &X, const DataFrame &negy);

    virtual void fit();
};


#endif //CPPFOREST_L2LINEAR_H
