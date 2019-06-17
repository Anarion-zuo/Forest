//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_EXPNODE_H
#define CPPFOREST_EXPNODE_H

#include "./monopNode.h"

class expNode : public monopNode {
public:
    expNode(numericNode* parent, bool lr, numericNode* left);
    ~expNode() = default;
    monopNode* _clone(numericNode* parent) override;
    double _compute(double n) override ;
    numericNode* _trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_EXPNODE_H
