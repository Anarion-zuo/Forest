//
// Created by anarion on 6/9/19.
//

#ifndef CPPFOREST_COSNODE_H
#define CPPFOREST_COSNODE_H

#include "../monopNode.h"

class cosNode : public monopNode {
public:
    cosNode(cgNode* parent, bool lr, cgNode* left);
    ~cosNode() = default;
    monopNode* _clone(cgNode* parent) override;
    double _compute(double n) override ;
    cgNode* _trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_COSNODE_H
