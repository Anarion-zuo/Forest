//
// Created by anarion on 7/11/19.
//

#ifndef CPPFOREST_BISECTIONROOTFINDER_H
#define CPPFOREST_BISECTIONROOTFINDER_H


#include "../../Solver.h"

class BisectionRootFinder : public Solver {
public:
    BisectionRootFinder(_cg* graph, SolverInput* info);
    ~BisectionRootFinder() override = default;

    void solve() override ;
};


#endif //CPPFOREST_BISECTIONROOTFINDER_H
