//
// Created by anarion on 7/12/19.
//

#ifndef CPPFOREST__POLY_NODE_H
#define CPPFOREST__POLY_NODE_H


#include "../_single_node.h"

class _poly_node : public _single_node {
protected:
    std::vector<double> _coeffs;
public:
    _poly_node(_cg_node* parent, _cg_node* child, std::vector<double>  coeffs);  // from 0 to n
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST__POLY_NODE_H
