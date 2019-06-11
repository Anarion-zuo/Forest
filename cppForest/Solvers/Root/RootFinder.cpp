//
// Created by anarion on 6/11/19.
//

#include "RootFinder.h"

RootFinder::RootFinder(SolverSetting *setting) : _setting(setting) {}

bool RootFinder::equals(double n1, double n2) {
    return n1 - n2 < _setting->get_epsilon() && n1 - n2 > -_setting->get_epsilon();
}
