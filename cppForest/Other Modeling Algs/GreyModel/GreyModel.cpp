//
// Created by anarion on 2019/8/4.
//

#include "GreyModel.h"

GreyModel::GreyModel() {

}

GreyModel::GreyModel(const std::vector<double> &seq) : _seq(seq) {

}

std::vector<double> GreyModel::ago() {
    std::vector<double> sa(_seq.size());
    double s = 0;
    for (size_t i = 0; i < _seq.size(); ++i){
        s += _seq[i];
        sa[i] = s;
    }
    return std::move(sa);
}

