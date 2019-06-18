//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_LNNODE_H
#define CPPFOREST_LNNODE_H


#include "../singleNode.h"

class lnNode : public singleNode {
public:
    lnNode(cgNode* parent, cgNode* child);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_LNNODE_H
