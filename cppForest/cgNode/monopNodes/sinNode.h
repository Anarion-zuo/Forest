//
// Created by a on 2019/5/15.
//

#ifndef CPPFOREST_SINNODE_H
#define CPPFOREST_SINNODE_H

#include "monopNode.h"

class sinNode : public monopNode {
    sinNode(cgNode* parent, bool lr, cgNode* left);
    ~sinNode() = default;
    monopNode* _clone(cgNode* parent) override;
    double _compute(double n) override ;
    cgNode* _trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_SINNODE_H
