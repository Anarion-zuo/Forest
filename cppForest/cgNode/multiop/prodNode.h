//
// Created by anarion on 2019/7/29.
//

#ifndef CPPFOREST_PRODNODE_H
#define CPPFOREST_PRODNODE_H


#include "../vectors/vecNode.h"

class prodNode : public vecNode{
protected:
    std::vector<cgNode*>&& _build_prod_recur(std::vector<cgNode*>& list);
    cgNode* _tree_form = nullptr;
public:
    prodNode(cgNode* parent, const std::vector<cgNode*>& childs);
    ~prodNode() override = default;
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
};


#endif //CPPFOREST_PRODNODE_H
