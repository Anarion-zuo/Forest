//
// Created by a on 2019/5/11.
//

#ifndef CPPFOREST_CONSTNODE_H
#define CPPFOREST_CONSTNODE_H

#include "cgNode.h"

class constNode : public cgNode {
public:
    constNode(cgNode* parent, bool lr, double val);
    ~constNode() = default;
    cgNode* clone(cgNode* parent);
    double compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
    void del() override ;
};


#endif //CPPFOREST_CONSTNODE_H
