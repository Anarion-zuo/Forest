//
// Created by anarion on 7/7/19.
//

#ifndef CPPFOREST__DCG_H
#define CPPFOREST__DCG_H

#include "../cgNode/_var.h"
#include "_cg.h"

class _cg;
class _dcg : public _cg {
public:
    explicit _dcg(_cg_node* root);
    explicit _dcg(_cg* graph);
    ~_dcg() = default;
    _cg* clone() override ;

    void compute(_var* x);
    inline void compute() override ;
};

void _dcg::compute() {
    _cg::compute();
}


#endif //CPPFOREST__DCG_H
