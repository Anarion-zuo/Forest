//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_VECNODE_H
#define CPPFOREST_VECNODE_H


#include "../cgNode.h"

class vecNode : public cgNode {
public:
    vecNode(cgNode* parent, const std::vector<cgNode*>& childs);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_VECNODE_H
