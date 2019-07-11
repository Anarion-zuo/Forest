#include <utility>

//
// Created by anarion on 7/8/19.
//

#include "SolverInput.h"

SolverInput::SolverInput(std::map<var *, Range *> ranges, double tolerance, size_t maxiter, double epsi) : _ranges(std::move(ranges)), _epsilon(tolerance), _max_iteration(maxiter), _precision(epsi) {

}

bool SolverInput::equals(double n1, double n2) {
    double ret = n1 - n2;
    if (ret < 0){
        ret = -ret;
    }
    return ret < _epsilon;
}

bool SolverInput::is_precise_enough(double n) {
    if (n < 0){
        n = -n;
    }
    return n < _precision;
}

bool SolverInput::exceeds_max_iter(size_t n) {
    return n > _max_iteration;
}

size_t SolverInput::var_number() {
    return _ranges.size();
}

const std::map<var *, Range *> &SolverInput::get_ranges() {
    return _ranges;
}

double SolverInput::get_epsilon() {
    return _epsilon;
}

size_t SolverInput::get_max_iteration() {
    return _max_iteration;
}

double SolverInput::get_precision() {
    return _precision;
}
