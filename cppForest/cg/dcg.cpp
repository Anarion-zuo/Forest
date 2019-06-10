//
// Created by anarion on 6/11/19.
//

#include "dcg.h"

dcg::dcg(cg *graph) : cg(graph) {
    _root = _root->diff();
    _dvars = varNode::_temp_dvars;
    varNode::clear_dvars();
}
