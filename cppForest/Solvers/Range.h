//
// Created by anarion on 7/8/19.
//

#ifndef CPPFOREST_RANGE_H
#define CPPFOREST_RANGE_H

#include <vector>

class Range {
protected:
    double _left;
    double _right;
public:
    Range(double left, double right);
    Range* clone();

    const std::vector<double> list(double step = 1);
};


#endif //CPPFOREST_RANGE_H
