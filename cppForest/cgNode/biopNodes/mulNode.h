//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_MULNODE_H
#define CPPFOREST_MULNODE_H

#include "../numericNode.h"

class mulNode : public numericNode {
public:
    mulNode(numericNode* parent, bool lr, numericNode* left, numericNode* right);
    ~mulNode() = default;
    numericNode* clone(numericNode* parent) override;
    double _compute(double n1, double n2) override ;
    numericNode* trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_MULNODE_H
