//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_CONSTNODE_H
#define CPPFOREST_CONSTNODE_H


#include "../singleNode.h"

class constNode : public singleNode {
private:
    double _val;
public:
    constNode(cgNode* parent, double val);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;

    double get_val() override ;
    void set_val(double val) override ;

    bool is_const() override ;
};


#endif //CPPFOREST_CONSTNODE_H
