//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST__L2_LR_CG_H
#define CPPFOREST__L2_LR_CG_H


#include "../../cg/_cg.h"

class _l2_lr_cg : public _cg {
protected:
    static _cg_node* _make_node(size_t dim);
public:
    _l2_lr_cg(size_t dim);

};


#endif //CPPFOREST__L2_LR_CG_H
