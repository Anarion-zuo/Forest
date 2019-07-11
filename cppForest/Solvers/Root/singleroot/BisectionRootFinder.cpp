//
// Created by anarion on 7/11/19.
//

#include "BisectionRootFinder.h"
#include "../../../MyException/SolverException/SingleVariableException.h"

BisectionRootFinder::BisectionRootFinder(cg *graph, SolverInput *info) : Solver(graph, info) {
    if (_input->var_number() != 1){
        throw SingleVariableException("Feeding multiple variables or none to a single root finder");
    }
}

void BisectionRootFinder::solve() {
    auto it = _input->get_ranges().begin();
    auto range = it->second;
    auto v = it->first;
    double left = range->get_left();
    double right = range->get_right();
    v->set_val(left);
    _graph->compute();
    double fl = _graph->get_result()->get_val();
    v->set_val(right);
    _graph->compute();
    double fr = _graph->get_result()->get_val();
    double mid = (left + right) / 2;
    v->set_val(mid);
    _graph->compute();
    double fm = _graph->get_result()->get_val();
    double prec = (right - left) / left;
    size_t i = 0;
    double pre = mid;
    double cur = 0;
    while(i < _input->get_max_iteration()){
        if (is_precise_enough(pre - cur)){
            break;
        }
        if (fm * fr < 0){
            mid = left;
        } else{
            mid = right;
        }
        v->set_val(left);
        _graph->compute();
        fl = _graph->get_result()->get_val();
        v->set_val(right);
        _graph->compute();
        fr = _graph->get_result()->get_val();
        mid = (left + right) / 2;
        v->set_val(mid);
        _graph->compute();
        fm = _graph->get_result()->get_val();
        ++i;
        prec = (right - left) / left;
        pre = cur;
        cur = mid;
    }
    delete _output;
    _output = new SolverOutput(i, fm);
}
