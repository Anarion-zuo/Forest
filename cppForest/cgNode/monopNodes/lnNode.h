//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_LNNODE_H
#define CPPFOREST_LNNODE_H

#include "monopNode.h"

class lnNode : public monopNode {
public:
    lnNode(numericNode* parent, bool lr, numericNode* left);
    ~lnNode() = default;
    monopNode* _clone(numericNode* parent) override;
    double _compute(double n) override ;
    numericNode* _trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_LNNODE_H
