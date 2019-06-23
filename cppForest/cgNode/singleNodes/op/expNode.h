//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST_EXPNODE_H
#define CPPFOREST_EXPNODE_H


#include "../singleNode.h"

class expNode : public singleNode {
public:
    expNode(cgNode* parent, cgNode* child);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_EXPNODE_H
