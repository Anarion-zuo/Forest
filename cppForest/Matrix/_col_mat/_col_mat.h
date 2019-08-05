//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST__COL_MAT_H
#define CPPFOREST__COL_MAT_H


#include <vector>
#include "../_matrix/_matrix.h"

class _col_mat : public _matrix{
protected:
    std::vector<std::string> _titles;
    std::vector<std::vector<double>> _cols;
public:
    _col_mat();
    _col_mat(const std::string&& dir);
};


#endif //CPPFOREST__COL_MAT_H
