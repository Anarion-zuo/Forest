//
// Created by anarion on 6/18/19.
//

#ifndef CPPFOREST_DOTNODE_H
#define CPPFOREST_DOTNODE_H


#include "../cgNode.h"
#include "../../MyException/VectorException/dotExceptions/dotSizeException.h"

class dotNode : public cgNode {
protected:
    cgNode*& _left = _childs[0];
    cgNode*& _right = _childs[1];
private:
public:
    dotNode(cgNode* parent, cgNode* left, cgNode* right) noexcept(false);
    virtual ~dotNode() = default;
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;

    size_t get_num_left();
    size_t get_num_right();
};


#endif //CPPFOREST_DOTNODE_H
