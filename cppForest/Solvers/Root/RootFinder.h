//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_ROOTFINDER_H
#define CPPFOREST_ROOTFINDER_H


#include "../SolverSetting/SolverSetting.h"
#include "../SolverResult/SolverResult.h"
#include "../../Function/Function.h"

class RootFinder {
protected:
    SolverSetting* _setting;
    SolverResult* _result = nullptr;
public:
    RootFinder(SolverSetting* setting);

    bool equals(double n1, double n2);
    virtual void solve(Function* function) = 0;
};


#endif //CPPFOREST_ROOTFINDER_H
