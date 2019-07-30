//
// Created by anarion on 2019/7/18.
//

#ifndef CPPFOREST_FIXEDPOINTROOTFINDER_H
#define CPPFOREST_FIXEDPOINTROOTFINDER_H


#include "../../Solver.h"

class FixedPointRootFinder : public Solver {
public:
    FixedPointRootFinder(_cg* graph, SolverInput* info);
    ~FixedPointRootFinder() override = default;

    void solve() override ;
};


#endif //CPPFOREST_FIXEDPOINTROOTFINDER_H
