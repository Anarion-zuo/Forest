//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_DIVNODE_H
#define CPPFOREST_DIVNODE_H

#include "cgNode.h"

class divNode : public cgNode {
public:
    divNode(cgNode* parent, bool lr, cgNode* left, cgNode* right);
    ~divNode() = default;
    cgNode* clone(cgNode* parent);
    double compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_DIVNODE_H
