//
// Created by anarion on 2019/7/25.
//

#ifndef CPPFOREST_SECANTROOTFINDER_H
#define CPPFOREST_SECANTROOTFINDER_H


#include "../../Solver.h"

class SecantRootFinder : public Solver {
protected:
public:
    SecantRootFinder(cg *graph, SolverInput *info);
    ~SecantRootFinder() override = default;

    void solve() override ;
};


#endif //CPPFOREST_SECANTROOTFINDER_H
