#include <utility>

//
// Created by anarion on 7/8/19.
//

#include "SolverInfo.h"

SolverInfo::SolverInfo(std::map<var *, Range *> ranges, double tolerance, size_t maxiter, double epsi) : _ranges(std::move(ranges)), _epsilon(tolerance), _max_iteration(maxiter), _precision(epsi) {

}
