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

    std::vector<double> list(double step = 1);
    bool is_in(double n);
    bool is_on_left(double n);
    bool is_on_right(double n);

    double get_left();
    double get_right();
};


#endif //CPPFOREST_RANGE_H
