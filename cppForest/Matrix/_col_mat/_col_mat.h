//
// Created by anarion on 2019/8/5.
//

#ifndef CPPFOREST__COL_MAT_H
#define CPPFOREST__COL_MAT_H


#include <vector>
#include "../_matrix/_matrix.h"
#include "../_entry/_entry.h"

class _col_mat{
protected:
    std::vector<std::string> _titles;
    std::vector<std::vector<double>> _cols;
public:
    _col_mat();
    explicit _col_mat(const std::string&& dir);

    size_t width();
    size_t height();
    double loc(size_t h, size_t w);

    // display
    void to_csv(const char* dir, size_t begin, size_t end);
    // encoding

};


#endif //CPPFOREST__COL_MAT_H
