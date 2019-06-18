//
// Created by anarion on 6/17/19.
//

#include "singleNode.h"

singleNode::singleNode(cgNode *parent, cgNode *child) : cgNode(parent, std::vector<cgNode*>(1, child)) {}

bool singleNode::is_single_val() {
    return true;
}
