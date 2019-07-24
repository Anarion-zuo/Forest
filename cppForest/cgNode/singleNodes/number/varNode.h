//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_VARNODE_H
#define CPPFOREST_VARNODE_H


#include "../../cgNode.h"
#include "../../var.h"
#include "../singleNode.h"

class varNode : public singleNode {
private:
    var* _var;
public:
    varNode(cgNode* parent, var* pvar);
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;

    double get_val() override ;
    void set_val(double val) override ;

    bool is_num() override ;
};


#endif //CPPFOREST_VARNODE_H
