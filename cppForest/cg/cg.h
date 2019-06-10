//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_CG_H
#define CPPFOREST_CG_H

#include "../cgNode/cgNode.h"
#include <vector>

class cg {
protected:
    cgNode* _root;
    std::vector<cgNode*> _vars;
public:
    cg(cgNode* root);
    cg(cg* graph);
    virtual ~cg();
};


#endif //CPPFOREST_CG_H
