//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST_ROOTNODE_H
#define CPPFOREST_ROOTNODE_H


#include "cgNode.h"

class rootNode : public cgNode {
    cgNode* &_child;
public:
    explicit rootNode(cgNode* child);
    virtual ~rootNode() = default;
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_ROOTNODE_H
