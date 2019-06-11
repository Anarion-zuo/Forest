//
// Created by anarion on 6/11/19.
//

#include "BisectionFinder.h"

BisectionFinder::BisectionFinder(SolverSetting *setting) : SingleVariableRootFinder(setting) {}

// measure accuracy in distance between left and right
void BisectionFinder::solve(Function *function) {
    Range* range = _setting->get_ranges()[0];
    double left = range->get_left(), right = range->get_right();
    double accuracy = std::numeric_limits<double>::max();
//    while (function->compute({left}) > 0 && function->compute({right}) > 0)
    double fl = function->compute({left});
    double fr = function->compute({right});
    double mid = (left + right) / 2;
    double fm = function->compute({mid});
    size_t i = 0;
    while(!(accuracy < _setting->get_accuracy() || equals(fm, 0))){
        bool lg = fl > 0, mg = fm > 0, rg = fr > 0;
        if ((lg || mg) && (!lg || !mg)){
            left = mid;
        }else if ((rg || mg) && (!rg || !mg)){
            right = mid;
        }
        fl = function->compute({left});
        fr = function->compute({right});
        mid = (left + right) / 2;
        fm = function->compute({mid});
        accuracy = right - left;
        ++i;
    }
    _result = new SolverResult(i, accuracy, fm, {mid});
}
