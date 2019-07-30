//
// Created by anarion on 7/2/19.
//

#ifndef CPPFOREST__VADD_NODE_H
#define CPPFOREST__VADD_NODE_H


#include "../_cg_node.h"

class _vadd_node : public _cg_node {
protected:
    _cg_node*& _left = _childs[0];
    _cg_node*& _right = _childs[1];
private:
public:
    _vadd_node(_cg_node* parent, _cg_node* left, _cg_node* right) noexcept(false);
    virtual ~_vadd_node() = default;
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;

    _cg_node* get_left();
    _cg_node* get_right();
};


#endif //CPPFOREST__VADD_NODE_H
