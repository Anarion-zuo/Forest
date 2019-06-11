//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_SOLVERRESULT_H
#define CPPFOREST_SOLVERRESULT_H


#include <glob.h>
#include <vector>

class SolverResult {
protected:
    double _accuracy;
    size_t _iterations;
    double _function_val;
    std::vector<double> _vars_val;
public:
    SolverResult(size_t iterations, double accuracy, double function_val, const std::vector<double>& vars_val);
};


#endif //CPPFOREST_SOLVERRESULT_H
