//
// Created by a on 2019/5/7.
//

#include "Garbage_Bin.h"

std::set<cgNode*> Garbage_Bin::_node_bin;

void Garbage_Bin::clear_bins() {
    for (auto it : _node_bin){
        delete it;
    }
}

void Garbage_Bin::push(cgNode *node) {
    _node_bin.insert(node);
}
