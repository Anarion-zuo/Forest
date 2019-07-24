//
// Created by anarion on 7/12/19.
//

#ifndef CPPFOREST_POLYNODE_H
#define CPPFOREST_POLYNODE_H


#include "../singleNode.h"

class polyNode : public singleNode {
protected:
    std::vector<double> _coeffs;
public:
    polyNode(cgNode* parent, cgNode* child, std::vector<double>  coeffs);  // from 0 to n
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;
};


#endif //CPPFOREST_POLYNODE_H
