//
// Created by anarion on 7/11/19.
//

#include "Solver.h"
#include "../MyException/nullException.h"

Solver::Solver(cg *graph, SolverInput *info, bool derivative) : _graph(graph), _input(info) {
    if (!graph){
        throw nullException("Feeding a null pointer to graph to solver.");
    }
    if (!_input){
        throw nullException("Feeding a null pointer to info to solver");
    }
    if (derivative){
        _dgraph = new dcg(_graph->clone());
    }
}



