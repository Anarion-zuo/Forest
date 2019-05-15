//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_EXPNODE_H
#define CPPFOREST_EXPNODE_H

#include "cgNode.h"

class expNode : public cgNode {
    expNode(cgNode* parent, bool lr, cgNode* left, cgNode* right);
    ~expNode() = default;
    cgNode* clone(cgNode* parent) override;
    double compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_EXPNODE_H
