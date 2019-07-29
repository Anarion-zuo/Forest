//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST_MULNODE_H
#define CPPFOREST_MULNODE_H

#include "../vectorOp/dotNode.h"

class mulNode : public cgNode {
protected:
    cgNode*& _left;
    cgNode*& _right;
public:
    mulNode(cgNode *parent, cgNode* left, cgNode* right);
    ~mulNode() override = default;
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_MULNODE_H
