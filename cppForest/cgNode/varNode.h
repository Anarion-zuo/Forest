//
// Created by a on 2019/5/11.
//

#ifndef CPPFOREST_VARNODE_H
#define CPPFOREST_VARNODE_H

#include "cgNode.h"
#include <map>

class varNode : public cgNode {
public:
    varNode(double val);
    ~varNode() = default;

    static std::map<cgNode*, varNode*> _temp_dvars;
    static void push_dvars(cgNode* n1, varNode* n2);
    static void clear_dvars();
    static varNode* get_dvar(cgNode* node);

    cgNode* clone(cgNode* parent);
    double compute(double n1, double n2) override ;
    cgNode* trim() override ;
    cgNode* diff() override ;
    void del() override ;
};


#endif //CPPFOREST_VARNODE_H
