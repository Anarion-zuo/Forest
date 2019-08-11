//
// Created by anarion on 2019/7/18.
//

#include "FixedPointRootFinder.h"
#include "../../../cgNode/singleNodes/number/_var_node.h"
#include "../../../cgNode/multiop/_sum_node.h"
#include "../../../MyException/SolverException/CannotConvergeException.h"
#include "../../../MyException/SolverException/SingleVariableException.h"

FixedPointRootFinder::FixedPointRootFinder(_cg *graph, SolverInput *info) : Solver(graph, info, false) {
    if (_input->var_number() != 1){
        throw SingleVariableException("Feeding multiple variables or none to a single root finder");
    }
    _var* var = _input->_ranges.begin()->first;
    auto x = new _var_node(nullptr, var);
    auto add = new _sum_node(nullptr, {_graph->_root->get_child(0), x});
    add->set_childs_parents();
    graph->_root->set_child(0, add);
    graph->_root->set_childs_parents();
}

void FixedPointRootFinder::solve() {
    double l = _input->_ranges.begin()->second->get_left();
    double r = _input->_ranges.begin()->second->get_right();
    double x = (l + r) / 2;
    size_t i = 0;
    double prec = 1e10;
    while (true){
        _var* v = _input->_ranges.begin()->first;
        v->set_val(x);
        _graph->compute();
        double xp = _graph->get_val();
        prec = x - xp;
        x = xp;
        if (exceeds_max_iter(i)){
            throw CannotConvergeException("Fixed point iteration cannot converge. Check whether the convergence condition is satisfied. The condition is that the absolute value of the derivative be strictly bounded by 1.");
        }
        if (is_precise_enough(prec, Solver::_flag_forward_error)){
            delete _output;
            _output = new SolverOutput(i, prec);
            return;
        }
        ++i;
    }
}
