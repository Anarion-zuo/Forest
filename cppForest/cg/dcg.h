//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_DCG_H
#define CPPFOREST_DCG_H

#include "cg.h"

class dcg : public cg {
protected:
    std::map<cgNode*, varNode*> _dvars;

public:
    dcg(cg* graph);
};


#endif //CPPFOREST_DCG_H
