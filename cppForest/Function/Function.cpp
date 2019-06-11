//
// Created by anarion on 6/9/19.
//

#include "Function.h"

Function::Function(cg *graph) : _graph(graph) {}

double Function::compute() {
    _graph->compute();
    return _graph->latest_result();
}
