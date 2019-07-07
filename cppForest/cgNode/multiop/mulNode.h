//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST_MULNODE_H
#define CPPFOREST_MULNODE_H

#include "../vectorOp/dotNode.h"

class mulNode : public dotNode {
protected:
public:
    mulNode(cgNode *parent, cgNode* left, cgNode* right);
    virtual ~mulNode() = default;
    cgNode* clone(cgNode* parent) override ;

};


#endif //CPPFOREST_MULNODE_H
