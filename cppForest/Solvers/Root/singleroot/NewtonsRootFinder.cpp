//
// Created by anarion on 2019/7/24.
//

#include "NewtonsRootFinder.h"
#include "../../../MyException/SolverException/SingleVariableException.h"
#include "../../../MyException/SolverException/CannotConvergeException.h"

NewtonsRootFinder::NewtonsRootFinder(_cg *graph, SolverInput *info) : Solver(graph, info, true) {
    if (_input->var_number() != 1){
        throw SingleVariableException("Feeding multiple variables or none to a single root finder");
    }
}

void NewtonsRootFinder::solve() {
    double xi = (_input->_ranges.begin()->second->get_left() + _input->_ranges.begin()->second->get_right()) / 2;
    _var* v = _input->_ranges.begin()->first;
    auto vit = _var::set_dvar(v);
    double f, df;
    size_t i = 0;
    while (true){
        double xii = xi;
        v->set_val(xi);
        _graph->compute();
        f = _graph->get_val();
        _dgraph->compute();
        df = _dgraph->get_val();
        xi -= f / df;
        if (exceeds_max_iter(i)){
            _var::clear_dvar(vit);
            throw CannotConvergeException("Newton's Method iteration cannot converge. Check whether the convergence condition is satisfied. The condition is that.");
        }
        if (is_precise_enough(xi - xii, Solver::_flag_forward_error)){
            delete _output;
            _output = new SolverOutput(i, xi - xii);
            _var::clear_dvar(vit);
            return;
        }
        ++i;
    }
}
