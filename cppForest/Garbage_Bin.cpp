//
// Created by a on 2019/5/7.
//

#include "Garbage_Bin.h"

std::deque<numericNode*> Garbage_Bin::_node_bin;

void Garbage_Bin::clear_bins() {
    _node_bin.clear();
}

void Garbage_Bin::push(numericNode *node) {
    _node_bin.push_back(node);
}
