//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_DIVNODE_H
#define CPPFOREST_DIVNODE_H

#include "../numericNode.h"

class divNode : public numericNode {
public:
    divNode(numericNode* parent, bool lr, numericNode* left, numericNode* right);
    ~divNode() = default;
    numericNode* clone(numericNode* parent) override ;
    double _compute(double n1, double n2) override ;
    numericNode* trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_DIVNODE_H
