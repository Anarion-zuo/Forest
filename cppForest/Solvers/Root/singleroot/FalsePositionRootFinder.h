//
// Created by anarion on 2019/7/25.
//

#ifndef CPPFOREST_FALSEPOSITIONROOTFINDER_H
#define CPPFOREST_FALSEPOSITIONROOTFINDER_H


#include "../../Solver.h"

class FalsePositionRootFinder : public Solver {
public:
    FalsePositionRootFinder(_cg *graph, SolverInput *info);
    ~FalsePositionRootFinder() override = default;

    void solve() override ;
};


#endif //CPPFOREST_FALSEPOSITIONROOTFINDER_H
