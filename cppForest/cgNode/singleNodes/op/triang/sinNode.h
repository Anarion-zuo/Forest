//
// Created by anarion on 2019/7/18.
//

#ifndef CPPFOREST_SINNODE_H
#define CPPFOREST_SINNODE_H


#include "../../singleNode.h"

class sinNode : public singleNode {
public:
    sinNode(cgNode* parent, cgNode* child);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_SINNODE_H
