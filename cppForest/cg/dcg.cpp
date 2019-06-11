//
// Created by anarion on 6/11/19.
//

#include "dcg.h"

dcg::dcg(cg *graph) : cg(graph) {
    _root = _root->diff();
    _dvars = var::get_map();
    var::clear_dvars();
}

dcg::dcg(dcg *dgraph) : cg(dgraph) {
    _root = _root->diff();
    _dvars = var::get_map();
    var::clear_dvars();
}

dcg *dcg::clone() {
    return new dcg(this);
}

void dcg::compute(var *var) {
    auto it = _dvars.find(var);
    if (it == _dvars.end()){
        return;
    }
    it->second->set_val(1);
    cg::compute();
    it->second->set_val(0);
}
