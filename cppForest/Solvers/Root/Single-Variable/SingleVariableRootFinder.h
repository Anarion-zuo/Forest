//
// Created by anarion on 6/9/19.
//

#ifndef CPPFOREST_SINGLEVARIABLEROOTFINDER_H
#define CPPFOREST_SINGLEVARIABLEROOTFINDER_H


#include "../RootFinder.h"

class SingleVariableRootFinder : public RootFinder {
public:
    SingleVariableRootFinder(SolverSetting* setting);
};


#endif //CPPFOREST_SINGLEVARIABLEROOTFINDER_H
