//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_CG_H
#define CPPFOREST_CG_H

#include "../cgNode/cgNode.h"
#include <vector>

class cg {
    friend class Function;
protected:
    cgNode* _root;
    std::vector<var*> _vars;
public:
    cg(cgNode* root);
    cg(cg* graph);
    virtual ~cg();

    virtual cg* clone();

    void compute();
    double latest_result();

    size_t var_nums();
    std::vector<var*>& get_vars();
};


#endif //CPPFOREST_CG_H
