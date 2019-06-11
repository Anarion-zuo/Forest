//
// Created by anarion on 6/11/19.
//

#include "SolverResult.h"

SolverResult::SolverResult(size_t iterations, double accuracy, double function_val, const std::vector<double>& vars_val) : _iterations(iterations), _accuracy(accuracy), _function_val(function_val), _vars_val(vars_val) {}
