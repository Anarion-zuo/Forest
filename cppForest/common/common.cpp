//
// Created by anarion on 2019/7/30.
//

#include "common.h"
#include <limits>

const double __epsilon = std::numeric_limits<double>::epsilon();

bool equals(double n1, double n2){
    double a = n1 - n2;
    if (a < 0){
        a = -a;
    }
    return a < __epsilon;
}