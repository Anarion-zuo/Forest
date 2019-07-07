//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_VECNODE_H
#define CPPFOREST_VECNODE_H


#include "../cgNode.h"

class vecNode : public cgNode {
public:
    vecNode(cgNode* parent, const std::vector<cgNode*>& childs);
    virtual cgNode* clone(cgNode* parent) override ;

    virtual void compute() override ;
    virtual void diff() override ;
    virtual void trim() override ;
};


#endif //CPPFOREST_VECNODE_H
