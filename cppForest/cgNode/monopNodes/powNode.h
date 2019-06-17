//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_POWNODE_H
#define CPPFOREST_POWNODE_H

#include "monopNode.h"

class powNode : public monopNode {
private:
    double _pow = 1;
public:
    powNode(numericNode* parent, bool lr, numericNode* left, double pow);
    ~powNode() = default;
    monopNode* _clone(numericNode* parent) override;
    double _compute(double n) override ;
    numericNode* _trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_POWNODE_H
