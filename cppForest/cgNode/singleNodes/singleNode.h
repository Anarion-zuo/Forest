//
// Created by anarion on 6/17/19.
//

#ifndef CPPFOREST_SINGLENODE_H
#define CPPFOREST_SINGLENODE_H


#include "../cgNode.h"

class singleNode : public cgNode {
protected:
    cgNode*& _child = _childs[0];
public:
    singleNode(cgNode* parent, cgNode* child);
    virtual ~singleNode() = default;

    bool is_single_val() override ;
};


#endif //CPPFOREST_SINGLENODE_H
