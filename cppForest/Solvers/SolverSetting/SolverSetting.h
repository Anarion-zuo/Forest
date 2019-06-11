//
// Created by anarion on 6/11/19.
//

#ifndef CPPFOREST_SOLVERSETTING_H
#define CPPFOREST_SOLVERSETTING_H

#include <vector>
#include "../../Function/Variable/Range.h"

class SolverSetting {
protected:
    std::vector<Range*> _ranges;
    size_t _max_iterations;
    double _accuracy;
    double _epsilon;
public:
    SolverSetting(size_t max_iterations, double accuracy, double epsilon, const std::vector<Range*>& ranges);
    ~SolverSetting() = default;

    std::vector<Range*>& get_ranges();
    size_t get_max_iterations();
    double get_accuracy();
    double get_epsilon();
};


#endif //CPPFOREST_SOLVERSETTING_H
