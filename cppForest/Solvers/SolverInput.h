//
// Created by anarion on 7/8/19.
//

#ifndef CPPFOREST_SOLVERINPUT_H
#define CPPFOREST_SOLVERINPUT_H


#include "Range.h"
#include "../cgNode/var.h"

class SolverInput {
protected:
    std::map<var*, Range*> _ranges;
    double _epsilon;
    size_t _max_iteration;
    double _precision;
public:
    SolverInput(std::map<var*, Range*>  ranges, double tolerance, size_t maxiter, double epsi);
    virtual ~SolverInput() = default;

    bool equals(double n1, double n2);
    bool is_precise_enough(double n);
    bool exceeds_max_iter(size_t n);
    size_t var_number();

    const std::map<var*, Range*>& get_ranges();
    double get_epsilon();
    size_t get_max_iteration();
    double get_precision();
};


#endif //CPPFOREST_SOLVERINPUT_H
