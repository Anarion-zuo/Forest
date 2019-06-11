//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_AFFINEFUNCTION_H
#define CPPFOREST_AFFINEFUNCTION_H


#include "../Function.h"

class AffineFunction : public Function {
public:
    AffineFunction(const std::vector<double>& as);

};


#endif //CPPFOREST_AFFINEFUNCTION_H
