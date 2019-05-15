//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_MONOPNODE_H
#define CPPFOREST_MONOPNODE_H

#include "../cgNode.h"

class monopNode : public cgNode {
public:
    monopNode(cgNode* parent, bool lr, cgNode* left);
    virtual ~monopNode() = default;
    cgNode* clone(cgNode* parent) override;
    virtual monopNode* _clone(cgNode* parent) = 0;
    cgNode* trim() override ;
    virtual _trim() = 0;
    double compute(double n1, double n2) override ;
    virtual double _compute(double n) = 0;
};


#include "lnNode.h"
#endif //CPPFOREST_MONOPNODE_H
