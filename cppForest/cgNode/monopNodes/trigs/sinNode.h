//
// Created by a on 2019/5/15.
//

#ifndef CPPFOREST_SINNODE_H
#define CPPFOREST_SINNODE_H

#include "../monopNode.h"

class sinNode : public monopNode {
public:
    sinNode(numericNode* parent, bool lr, numericNode* left);
    ~sinNode() = default;
    monopNode* _clone(numericNode* parent) override;
    double _compute(double n) override ;
    numericNode* _trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_SINNODE_H
