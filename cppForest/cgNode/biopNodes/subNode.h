//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_SUBNODE_H
#define CPPFOREST_SUBNODE_H

#include "../cgNode.h"

class subNode : public cgNode {
public:
    subNode(cgNode* parent, bool lr, cgNode* left, cgNode* right);
    ~subNode() = default;
    cgNode* clone(cgNode* parent) override ;
    double _compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_SUBNODE_H
