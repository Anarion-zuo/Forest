//
// Created by anarion on 6/9/19.
//

#ifndef CPPFOREST_FUNCTION_H
#define CPPFOREST_FUNCTION_H

#include "Variable/Variable.h"
#include "../cg/cg.h"


class Function {
protected:
//    std::vector<Variable*> _xs;
    cg* _graph;

public:
    Function(){}
    Function(cg* graph);

    std::vector<var*>& get_vars();
    double compute();
    double compute(const std::vector<double>& nums);
};


#endif //CPPFOREST_FUNCTION_H
