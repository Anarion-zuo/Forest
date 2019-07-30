//
// Created by anarion on 2019/7/30.
//

#ifndef CPPFOREST__CNST_VEC_H
#define CPPFOREST__CNST_VEC_H


#include "_cnst_mat.h"

class _cnst_vec : public _cnst_mat {
public:
    _cnst_vec();
    _cnst_vec(double n, size_t dm);
    _cnst_vec(size_t dm);
};


#endif //CPPFOREST__CNST_VEC_H
