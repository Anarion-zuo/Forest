//
// Created by anarion on 7/8/19.
//

#ifndef CPPFOREST_SOLVERINPUT_H
#define CPPFOREST_SOLVERINPUT_H


#include <limits>
#include "Range.h"
#include "../cgNode/var.h"

struct _numer_error_{
    double forw;
    double back;
    _numer_error_(double forward, double backward) : forw(forward), back(backward) {}
};

class SolverInput {
public:
    std::map<var*, Range*> _ranges;
    double _epsilon;
    size_t _max_iteration;
    _numer_error_ _error;
    SolverInput(std::map<var*, Range*>  ranges, double error, size_t maxiter, double epsi = std::numeric_limits<double>::epsilon(), double forward = std::numeric_limits<double>::epsilon(), double backward = std::numeric_limits<double>::epsilon());
    virtual ~SolverInput() = default;

    static void register_range(std::map<var*, Range*>& map, var* x, double left, double right);

    bool equals(double n1, double n2);
    bool is_precise_enough(double n, bool eflag = false);
    bool exceeds_max_iter(size_t n);
    size_t var_number();
};


#endif //CPPFOREST_SOLVERINPUT_H
