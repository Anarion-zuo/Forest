//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST__RANGE_NODE_H
#define CPPFOREST__RANGE_NODE_H


#include <map>
#include "../_cg_node.h"

class _range_node : _cg_node {
protected:
    std::vector<double> _threash;
    std::vector<_cg_node*> _ops;
    _cg_node*& _child;

    static double choose_op(double res, const std::vector<double>& threash);
public:
    _range_node(_cg_node *parent, _cg_node *child, std::vector<double> threash, std::vector<_cg_node *> ops);
    ~_range_node() override = default;

    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__RANGE_NODE_H
