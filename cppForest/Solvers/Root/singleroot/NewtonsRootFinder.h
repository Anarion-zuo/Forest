//
// Created by anarion on 2019/7/24.
//

#ifndef CPPFOREST_NEWTONSROOTFINDER_H
#define CPPFOREST_NEWTONSROOTFINDER_H


#include "../../Solver.h"

class NewtonsRootFinder : public Solver {
public:
    NewtonsRootFinder(cg *graph, SolverInput *info);
    ~NewtonsRootFinder() override = default;

    void solve() override ;
};


#endif //CPPFOREST_NEWTONSROOTFINDER_H
