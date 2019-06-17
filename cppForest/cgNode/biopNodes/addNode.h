//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_ADDNODE_H
#define CPPFOREST_ADDNODE_H

#include "../numericNode.h"

class addNode : public numericNode {
public:
    addNode(numericNode* parent, bool lr, numericNode* left, numericNode* right);
    ~addNode() = default;
    numericNode* clone(numericNode* parent) override ;
    double _compute(double n1, double n2) override ;
    numericNode* trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_ADDNODE_H
