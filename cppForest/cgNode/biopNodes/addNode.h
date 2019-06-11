//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_ADDNODE_H
#define CPPFOREST_ADDNODE_H

#include "../cgNode.h"

class addNode : public cgNode {
public:
    addNode(cgNode* parent, bool lr, cgNode* left, cgNode* right);
    ~addNode() = default;
    cgNode* clone(cgNode* parent) override ;
    double _compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_ADDNODE_H
