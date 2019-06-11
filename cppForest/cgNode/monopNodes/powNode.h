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
    powNode(cgNode* parent, bool lr, cgNode* left, double pow);
    ~powNode() = default;
    monopNode* _clone(cgNode* parent) override;
    double _compute(double n) override ;
    cgNode* _trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_POWNODE_H
