//
// Created by anarion on 6/11/19.
//

#include "SolverSetting.h"

SolverSetting::SolverSetting(size_t max_iterations, double accuracy, double epsilon, const std::vector<Range *> &ranges) : _max_iterations(max_iterations), _accuracy(accuracy), _ranges(ranges), _epsilon(epsilon) {}

std::vector<Range *> &SolverSetting::get_ranges() {
    return _ranges;
}

size_t SolverSetting::get_max_iterations() {
    return _max_iterations;
}

double SolverSetting::get_accuracy() {
    return _accuracy;
}

double SolverSetting::get_epsilon() {
    return _epsilon;
}

