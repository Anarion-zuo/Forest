//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_SUBNODE_H
#define CPPFOREST_SUBNODE_H

#include "../numericNode.h"

class subNode : public numericNode {
public:
    subNode(numericNode* parent, bool lr, numericNode* left, numericNode* right);
    ~subNode() = default;
    numericNode* clone(numericNode* parent) override ;
    double _compute(double n1, double n2) override ;
    numericNode* trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_SUBNODE_H
