//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST_CG_H
#define CPPFOREST_CG_H

#include "../cgNode/cgNode.h"
#include "dcg.h"

class dcg;
class cg {
protected:
    cgNode* _root;
public:
    explicit cg(cgNode* root);
    virtual ~cg();
    cg* clone();

    void compute();
    cgNode* get_result();
    dcg* diff();
};


#endif //CPPFOREST_CG_H
