//
// Created by anarion on 2019/7/18.
//

#ifndef CPPFOREST_COSNODE_H
#define CPPFOREST_COSNODE_H


#include "../../singleNode.h"

class cosNode : public singleNode {
public:
    cosNode(cgNode* parent, cgNode* child);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_COSNODE_H
