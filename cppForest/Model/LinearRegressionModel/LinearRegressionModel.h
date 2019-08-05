//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST_LINEARREGRESSIONMODEL_H
#define CPPFOREST_LINEARREGRESSIONMODEL_H


#include <vector>
#include "../../cgNode/_cg_node.h"
#include "../Model.h"

class LinearRegressionModel : public Model{
protected:
    std::vector<_var*> _coeff, _input;
    size_t _dim;
public:
    explicit LinearRegressionModel(_col_mat* data);
    ~LinearRegressionModel() override = default;

    void fit() override ;
};


#endif //CPPFOREST_LINEARREGRESSIONMODEL_H
