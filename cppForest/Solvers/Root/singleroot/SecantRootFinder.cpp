//
// Created by anarion on 2019/7/25.
//

#include "SecantRootFinder.h"
#include "../../../MyException/SolverException/SingleVariableException.h"
#include "../../../MyException/SolverException/CannotConvergeException.h"

SecantRootFinder::SecantRootFinder(_cg *graph, SolverInput *info) : Solver(graph, info, false) {
    if (_input->var_number() != 1){
        throw SingleVariableException("Feeding multiple variables or none to a single root finder");
    }
}

void SecantRootFinder::solve() {
    double xi = _input->_ranges.begin()->second->get_left(),
    xii = _input->_ranges.begin()->second->get_right();
    _var* v = _input->_ranges.begin()->first;
    size_t i = 0;
    double fi, fii, xiii;
    while (true) {
        v->set_val(xi);
        _graph->compute();
        fi = _graph->get_result()->get_val();
        v->set_val(xii);
        _graph->compute();
        fii = _graph->get_result()->get_val();
        xiii = xii - fii * (xii - xi) / (fii - fi);
        if (exceeds_max_iter(i)){
            throw CannotConvergeException("Secant Method iteration cannot converge. Check whether the convergence condition is satisfied. The condition is that.");
        }
        if (is_precise_enough(xiii - xii, Solver::_flag_forward_error)){
            delete _output;
            _output = new SolverOutput(i, xi - xii);
            return;
        }
        xi = xii;
        xii = xiii;
        ++i;
    }

}
