//
// Created by anarion on 6/23/19.
//

#ifndef CPPFOREST_MATNODE_H
#define CPPFOREST_MATNODE_H

#include "vecNode.h"

class matNode : public vecNode{
public:
    matNode(cgNode* parent, const std::vector<cgNode*>& childs);


};


#endif //CPPFOREST_MATNODE_H
