//
// Created by anarion on 7/11/19.
//

#ifndef CPPFOREST_SOLVER_H
#define CPPFOREST_SOLVER_H


#include "../cg/cg.h"
#include "SolverInput.h"
#include "SolverOutput.h"

class Solver {
protected:
    cg* _graph;
    SolverInput* _input;
    SolverOutput* _output;
public:
    Solver(cg* graph, SolverInput* info);
    virtual ~Solver() = default;

    virtual void solve() = 0;

    inline bool equals(double n1, double n2);
    inline bool is_precise_enough(double n);
    inline bool exceeds_max_iter(size_t n);
};

bool Solver::equals(double n1, double n2) {
    return _input->equals(n1, n2);
}

bool Solver::is_precise_enough(double n) {
    return _input->is_precise_enough(n);
}

bool Solver::exceeds_max_iter(size_t n) {
    return _input->exceeds_max_iter(n);
}

#endif //CPPFOREST_SOLVER_H
