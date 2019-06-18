//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_POWNODE_H
#define CPPFOREST_POWNODE_H


#include "../singleNode.h"

class powNode : public singleNode {
protected:
    double _pow;
public:
    powNode(cgNode* parent, cgNode* child, double pow);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_POWNODE_H
