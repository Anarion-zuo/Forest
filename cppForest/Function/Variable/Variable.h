//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_VARIABLE_H
#define CPPFOREST_VARIABLE_H


#include "Range.h"
#include "var.h"

class Variable {
protected:
    Range* _range;
    var* _var;
public:
    Variable(double n, double left, double right);
    ~Variable();

    // range
    void change_range(double left, double right);
    double get_range_left();
    double get_range_right();

    //
};


#endif //CPPFOREST_VARIABLE_H
