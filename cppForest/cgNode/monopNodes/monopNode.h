//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_MONOPNODE_H
#define CPPFOREST_MONOPNODE_H

#include "../numericNode.h"

class monopNode : public numericNode {
public:
    monopNode(numericNode* parent, bool lr, numericNode* left);
    virtual ~monopNode() = default;
    numericNode* clone(numericNode* parent) override;
    virtual monopNode* _clone(numericNode* parent) = 0;
    numericNode* trim() override ;
    virtual numericNode *_trim() = 0;
    double compute() override ;
    virtual double _compute(double n) = 0;
    double _compute(double n1, double n2) override {}
};


#include "lnNode.h"
#endif //CPPFOREST_MONOPNODE_H
