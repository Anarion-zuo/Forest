//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_BISECTIONFINDER_H
#define CPPFOREST_BISECTIONFINDER_H


#include "SingleVariableRootFinder.h"

class BisectionFinder : public SingleVariableRootFinder {
public:
    BisectionFinder(SolverSetting* setting);

    void solve(Function* function) override ;
};


#endif //CPPFOREST_BISECTIONFINDER_H
