//
// Created by anarion on 6/13/19.
//

#ifndef CPPFOREST_VECTORNODE_H
#define CPPFOREST_VECTORNODE_H


#include "../numericNode.h"

class vectorNode {
protected:
    std::vector<numericNode*> _childs;
public:
    vectorNode(numericNode* parent, bool lr, const std::vector<numericNode*>& childs);

    bool is_vector() ;
    void del() ;
    vectorNode* clone(numericNode* parent) ;

    numericNode* trim() override ;
    numericNode* diff() override ;
};


#endif //CPPFOREST_VECTORNODE_H
