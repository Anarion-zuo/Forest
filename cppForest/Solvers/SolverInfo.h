//
// Created by anarion on 7/8/19.
//

#ifndef CPPFOREST_SOLVERINFO_H
#define CPPFOREST_SOLVERINFO_H


#include "Range.h"
#include "../cgNode/var.h"

class SolverInfo {
protected:
    std::map<var*, Range*> _ranges;
    double _epsilon;
    size_t _max_iteration;
    double _precision;
public:
    SolverInfo(std::map<var*, Range*>  ranges, double tolerance, size_t maxiter, double epsi);
};


#endif //CPPFOREST_SOLVERINFO_H
