//
// Created by anarion on 2019/7/29.
//

#ifndef CPPFOREST__CNST_MAT_H
#define CPPFOREST__CNST_MAT_H


#include <glob.h>
#include <string>
#include <vector>
#include "../_matrix/_matrix.h"

class _cnst_mat {
private:
    _cnst_mat(_cnst_mat&);
protected:
    double* _mat;
    size_t _size, _width, _height;

    // Gaussian
//    static std::vector<_cnst_mat*>&& _perfect_cond(_cnst_mat* input, const std::vector<_cnst_mat*>& rhs);
public:
    _cnst_mat();
    _cnst_mat(size_t height, size_t width);
    _cnst_mat(double n, size_t height, size_t width);
    _cnst_mat(double* mat, size_t height, size_t width);
    explicit _cnst_mat(std::vector<std::vector<double>>&& vec);
    ~_cnst_mat();
    _cnst_mat* clone();

    void reshape(size_t height, size_t width);
    static _cnst_mat * arrange(double begin, double end, double step);

    // serialize
    std::string to_string();

    // access matrix
    double& loc(size_t i, size_t j);

    // arithmetic
    static void negative(_cnst_mat* m);
    static _cnst_mat* add(_cnst_mat* ma, _cnst_mat* mb);
    static _cnst_mat* sub(_cnst_mat* ma, _cnst_mat* mb);
    void times_const(double n);
    static _cnst_mat* _naive_mul(_cnst_mat* ma, _cnst_mat* mb);

    // transform
    void swap_rows(size_t index1, size_t index2);
    void swap_cols(size_t index1, size_t index2);

    void scale_row(size_t index, double n);
    void scale_col(size_t index, double n);

    void plus_row(size_t srow, size_t drow);
    void plus_col(size_t scol, size_t dcol);

    static std::vector<_cnst_mat*> _perfect_cond(_cnst_mat* input, const std::vector<_cnst_mat*>& rhs);

};


#endif //CPPFOREST__CNST_MAT_H
