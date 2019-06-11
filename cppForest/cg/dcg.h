//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_DCG_H
#define CPPFOREST_DCG_H

#include "cg.h"

class dcg : public cg {
protected:
    std::map<var*, var*> _dvars;

public:
    dcg(cg* graph);
    dcg(dcg* dgraph);

    dcg* clone() override ;

    void compute(var* var);
};


#endif //CPPFOREST_DCG_H
