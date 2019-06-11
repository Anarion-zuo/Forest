//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_EXPNODE_H
#define CPPFOREST_EXPNODE_H

#include "../cgNode.h"

class expNode : public monopNode {
    expNode(cgNode* parent, bool lr, cgNode* left);
    ~expNode() = default;
    monopNode* _clone(cgNode* parent) override;
    double _compute(double n) override ;
    cgNode* _trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_EXPNODE_H
