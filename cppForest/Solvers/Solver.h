//
// Created by anarion on 7/11/19.
//

#ifndef CPPFOREST_SOLVER_H
#define CPPFOREST_SOLVER_H


#include "../cg/_cg.h"
#include "SolverInput.h"
#include "SolverOutput.h"
#include "../cg/_dcg.h"

class Solver {
protected:
    _cg* _graph;
    SolverInput* _input;
    SolverOutput* _output = nullptr;
    _dcg* _dgraph = nullptr;
    static const bool _flag_forward_error = false;
    static const bool _flag_backward_error = true;
    static const bool _flag_use_derivative = true;
public:
    Solver(_cg* graph, SolverInput* info, bool derivative);
    virtual ~Solver() = default;

    virtual void solve() = 0;

    inline bool equals(double n1, double n2);
    inline bool is_precise_enough(double n, bool flag);
    inline bool exceeds_max_iter(size_t n);
};

bool Solver::equals(double n1, double n2) {
    return _input->equals(n1, n2);
}

bool Solver::is_precise_enough(double n, bool flag) {
    return _input->is_precise_enough(n);
}

bool Solver::exceeds_max_iter(size_t n) {
    return _input->exceeds_max_iter(n);
}

#endif //CPPFOREST_SOLVER_H
