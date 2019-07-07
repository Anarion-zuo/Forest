//
// Created by anarion on 6/17/19.
//

#ifndef CPPFOREST_SUMNODE_H
#define CPPFOREST_SUMNODE_H


#include "../vectorOp/dotNode.h"

class sumNode : public dotNode {
private:

public:
    sumNode(cgNode* parent, const std::vector<cgNode*>& childs);
    cgNode* clone(cgNode* parent) override ;

    void diff() override ;

};


#endif //CPPFOREST_SUMNODE_H
