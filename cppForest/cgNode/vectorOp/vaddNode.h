//
// Created by anarion on 7/2/19.
//

#ifndef CPPFOREST_VADDNODE_H
#define CPPFOREST_VADDNODE_H


#include "../cgNode.h"

class vaddNode : public cgNode {
protected:
    cgNode*& _left = _childs[0];
    cgNode*& _right = _childs[1];
private:
public:
    vaddNode(cgNode* parent, cgNode* left, cgNode* right) noexcept(false);
    virtual ~vaddNode() = default;
    cgNode* clone(cgNode* parent) override ;

    void compute() override ;
    void diff() override ;
    void trim() override ;

    cgNode* get_left();
    cgNode* get_right();
};


#endif //CPPFOREST_VADDNODE_H
