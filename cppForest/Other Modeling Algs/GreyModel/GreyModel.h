//
// Created by anarion on 2019/8/4.
//

#ifndef CPPFOREST_GREYMODEL_H
#define CPPFOREST_GREYMODEL_H


#include <glob.h>
#include <vector>

class GreyModel {
protected:
    std::vector<double> _seq;
public:
    GreyModel();
    explicit GreyModel(const std::vector<double>& seq);

    std::vector<double> ago();
};


#endif //CPPFOREST_GREYMODEL_H
