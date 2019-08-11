//
// Created by anarion on 2019/7/25.
//

#include "FalsePositionRootFinder.h"
#include "../../../MyException/SolverException/CannotConvergeException.h"
#include "../../../MyException/SolverException/SingleVariableException.h"
#include "../../../MyException/SolverException/ConditionException.h"

FalsePositionRootFinder::FalsePositionRootFinder(_cg *graph, SolverInput *info) : Solver(graph, info, false) {
    if (_input->var_number() != 1){
        throw SingleVariableException("Feeding multiple variables or none to a single root finder");
    }
}

void FalsePositionRootFinder::solve() {
    auto it = _input->_ranges.begin();
    double a = it->second->get_left();
    double b = it->second->get_right();
    _var* x = it->first;
    x->set_val(a);
    _graph->compute();
    double fa = _graph->get_val();
    x->set_val(b);
    _graph->compute();
    double fb = _graph->get_val();
    if ((fa > 0 && fb > 0) || (fa < 0 && fb < 0)){
        std::string s1("False Position Method got the same sign on both ends. left: ");
        std::string s2("  right: ");
        throw ConditionException(s1 + std::to_string(fa) + s2 + std::to_string(fb));
    }
    if (equals(0, fa)){
        delete _output;
        x->set_val(a);
        _output = new SolverOutput(0, 1);
        return;
    }
    if (equals(0, fb)){
        delete _output;
        x->set_val(b);
        _output = new SolverOutput(0, 1);
        return;
    }
    double c, fc;
    size_t i = 0;
    while (true) {
        double q = fb / fa;
        c = (b - a * q) / (1 - q);
        x->set_val(c);
        _graph->compute();
        fc = _graph->get_val();
        if (equals(fc, 0)){
            delete _output;
            _output = new SolverOutput(i, c);
            return;
        }
        if (exceeds_max_iter(i)){
            throw CannotConvergeException("False Position Method iteration cannot converge. Check whether the convergence condition is satisfied. The condition is that.");
        }
        if ((fa < 0 && fc > 0) || (fa > 0 && fc < 0)){
            b = c;
        } else {
            a = c;
        }
        x->set_val(a);
        _graph->compute();
        fa = _graph->get_val();
        x->set_val(b);
        _graph->compute();
        fb = _graph->get_val();
        ++i;
    }

}