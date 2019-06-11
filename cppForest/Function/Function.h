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

    double compute();
};


#endif //CPPFOREST_FUNCTION_H
