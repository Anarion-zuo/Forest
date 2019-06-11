//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_LNNODE_H
#define CPPFOREST_LNNODE_H

#include "monopNode.h"

class lnNode : public monopNode {
public:
    lnNode(cgNode* parent, bool lr, cgNode* left);
    ~lnNode() = default;
    monopNode* _clone(cgNode* parent) override;
    double _compute(double n) override ;
    cgNode* _trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_LNNODE_H
