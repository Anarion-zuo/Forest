//
// Created by anarion on 6/13/19.
//

#ifndef CPPFOREST_VECTORNODE_H
#define CPPFOREST_VECTORNODE_H


#include "../cgNode.h"

class vectorNode : public cgNode{
protected:
    std::vector<cgNode*> _childs;
public:
    vectorNode(cgNode* parent, bool lr, const std::vector<cgNode*>& childs);

    bool is_vector() override ;
    void del() override ;
    cgNode* clone(cgNode* parent) override ;

    double _compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
};


#endif //CPPFOREST_VECTORNODE_H
