//
// Created by anarion on 6/9/19.
//

#include "Function.h"

Function::Function(cg *graph) : _graph(graph) {}

double Function::compute() {
    _graph->compute();
    return _graph->latest_result();
}

std::vector<var *> &Function::get_vars() {
    return _graph->get_vars();
}

double Function::compute(const std::vector<double> &nums) {
    for (size_t i = 0; i < _graph->get_vars().size(); ++i){
        _graph->get_vars()[i]->set_val(nums[i]);
    }
    return compute();
}
