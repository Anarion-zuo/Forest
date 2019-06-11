//
// Created by a on 2019/5/11.
//

#ifndef CPPFOREST_VARNODE_H
#define CPPFOREST_VARNODE_H

#include "../cgNode.h"
#include <map>
#include "../../Function/Variable/var.h"

class varNode : public cgNode {
private:
    var* _var;
public:
    varNode(cgNode* parent, bool lr, var* v);
    ~varNode() = default;

    cgNode* clone(cgNode* parent);
    double compute() override ;
    double _compute(double n1, double n2) override {}
    cgNode* trim() override ;
    cgNode* diff() override ;
    void del() override ;

    bool is_var() override;

    void set_var(var* v);
    var* get_var();

private:
    static void _change_child_to_d(varNode *var, varNode* dvar);
};



#endif //CPPFOREST_VARNODE_H
