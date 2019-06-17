//
// Created by anarion on 6/13/19.
//

#ifndef CPPFOREST_VECTOROPNODE_H
#define CPPFOREST_VECTOROPNODE_H


#include "../numericNode.h"

class vectorOpNode{
protected:
    vectorOpNode* _left;
    vectorOpNode* _right;
public:
    vectorOpNode(numericNode *parent, vectorOpNode* left, vectorOpNode* right);

    void del();
    vectorOpNode* clone(numericNode* parent);

    numericNode* trim();
    numericNode* diff();
};


#endif //CPPFOREST_VECTOROPNODE_H
