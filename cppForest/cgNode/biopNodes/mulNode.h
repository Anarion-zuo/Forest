//
// Created by a on 2019/5/7.
//

#ifndef CPPFOREST_MULNODE_H
#define CPPFOREST_MULNODE_H

#include "../cgNode.h"

class mulNode : public cgNode {
public:
    mulNode(cgNode* parent, bool lr, cgNode* left, cgNode* right);
    ~mulNode() = default;
    cgNode* clone(cgNode* parent) override;
    double _compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_MULNODE_H
