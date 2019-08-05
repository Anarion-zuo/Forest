//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST_MODEL_H
#define CPPFOREST_MODEL_H


#include "../cg/_cg.h"
#include "../cgNode/_var.h"
#include "../Matrix/_col_mat/_col_mat.h"
#include "../cg/_dcg.h"

class Model {
protected:
    const _cg* _target;
    const _dcg* _dtarget;
    _col_mat* _data;
public:
    Model();
    explicit Model(_col_mat* data);
    virtual ~Model() = default;

    virtual void fit() = 0;
};


#endif //CPPFOREST_MODEL_H
