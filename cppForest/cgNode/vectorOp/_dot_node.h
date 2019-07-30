//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST__DOT_NODE_H
#define CPPFOREST__DOT_NODE_H


#include "../_cg_node.h"
#include "../../MyException/VectorException/dotExceptions/vecSizeException.h"

class _dot_node : public _cg_node {
protected:
    _cg_node*& _left = _childs[0];
    _cg_node*& _right = _childs[1];
private:
public:
    _dot_node(_cg_node* parent, _cg_node* left, _cg_node* right) noexcept(false);
    virtual ~_dot_node() = default;
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    virtual void diff() override ;
    void trim() override ;

    size_t get_num_left();
    size_t get_num_right();
};


#endif //CPPFOREST__DOT_NODE_H
