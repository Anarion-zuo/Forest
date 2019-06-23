//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST_NUMMULNODE_H
#define CPPFOREST_NUMMULNODE_H


#include "../cgNode.h"

class nummulNode : public cgNode {
protected:
    cgNode* &_left;
    cgNode* &_right;
public:
    nummulNode(cgNode* parent, cgNode* left, cgNode* right); // the left node must be of single type
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_NUMMULNODE_H
