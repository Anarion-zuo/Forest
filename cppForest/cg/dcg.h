//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST_DCG_H
#define CPPFOREST_DCG_H

#include "../cgNode/var.h"
#include "cg.h"

class cg;
class dcg : public cg {
public:
    explicit dcg(cgNode* root);
    explicit dcg(cg* graph);
    ~dcg() = default;
    cg* clone() override ;

    void compute(var* x);
    inline void compute() override ;
};

void dcg::compute() {
    cg::compute();
}


#endif //CPPFOREST_DCG_H
