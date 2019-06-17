//
// Created by anarion on 6/9/19.
//

#ifndef CPPFOREST_COSNODE_H
#define CPPFOREST_COSNODE_H

#include "../monopNode.h"

class cosNode : public monopNode {
public:
    cosNode(numericNode* parent, bool lr, numericNode* left);
    ~cosNode() = default;
    monopNode* _clone(numericNode* parent) override;
    double _compute(double n) override ;
    numericNode* _trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_COSNODE_H
