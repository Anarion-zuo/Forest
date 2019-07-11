//
// Created by anarion on 7/8/19.
//

#ifndef CPPFOREST_SOLVEROUTPUT_H
#define CPPFOREST_SOLVEROUTPUT_H


#include "../cgNode/var.h"

class SolverOutput {
protected:
    size_t _iteration;
    double _precision;
public:
    SolverOutput(size_t iter, double prec);
};


#endif //CPPFOREST_SOLVEROUTPUT_H
