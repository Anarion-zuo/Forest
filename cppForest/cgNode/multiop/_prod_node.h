//
// Created by anarion on 2019/7/29.
//

#ifndef CPPFOREST__PROD_NODE_H
#define CPPFOREST__PROD_NODE_H


#include "../vectors/_vec_node.h"

class _prod_node : public _vec_node{
protected:
    std::vector<_cg_node*>&& _build_prod_recur(std::vector<_cg_node*>& list);
    _cg_node* _tree_form = nullptr;
public:
    _prod_node(_cg_node* parent, const std::vector<_cg_node*>& childs);
    ~_prod_node() override = default;
    _cg_node* clone(_cg_node* parent) override ;

    void compute() override ;
    void diff() override ;
};


#endif //CPPFOREST__PROD_NODE_H
