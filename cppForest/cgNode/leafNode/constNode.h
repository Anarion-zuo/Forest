//
// Created by a on 2019/5/11.
//

#ifndef CPPFOREST_CONSTNODE_H
#define CPPFOREST_CONSTNODE_H

#include "../numericNode.h"

class constNode : public numericNode {
public:
    constNode(numericNode* parent, bool lr, double val);
    ~constNode() = default;
    numericNode* clone(numericNode* parent);
    double compute() override ;
    double _compute(double n1, double n2) override {}
    numericNode* trim() override ;
    numericNode* diff() override ;
    void del() override ;

    bool is_n_node(double n) override ;
    bool is_const() override ;
};


#endif //CPPFOREST_CONSTNODE_H
