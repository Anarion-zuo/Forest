//
// Created by a on 2019/5/14.
//

#ifndef CPPFOREST_CG_H
#define CPPFOREST_CG_H

#include "../cgNode/cgNode.h"

class cg {
protected:
    cgNode* _root;
public:
    cg(cgNode* root);
    virtual ~cg();
};


#endif //CPPFOREST_CG_H
