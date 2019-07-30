//
// Created by anarion on 2019/7/29.
//

#ifndef CPPFOREST__CNST_MAT_H
#define CPPFOREST__CNST_MAT_H


#include <glob.h>
#include <string>

class _cnst_mat {
protected:
    double* _mat;
    size_t _width, _height, _size;

    // Gaussian
public:
    _cnst_mat();
    _cnst_mat(size_t height, size_t width);
    _cnst_mat(double n, size_t height, size_t width);
    _cnst_mat(double* mat, size_t height, size_t width);
    virtual ~_cnst_mat();
    _cnst_mat* clone();
    size_t get_width();
    size_t get_height();

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
    
    // Gaussian
    static void _eliminate(_cnst_mat* in, size_t rowi, size_t coli);
    static void _eliminate_with(_cnst_mat* in, _cnst_mat* perm, _cnst_mat *b, size_t rowi, size_t coli);
    static size_t _largest_row(_cnst_mat* in, size_t rowi, size_t coli);
    static void _LU_fact(_cnst_mat* in, _cnst_mat *b, _cnst_mat** l, _cnst_mat** u, _cnst_mat** newb, size_t** order);
    static void _solve_lcpb(_cnst_mat* lm, _cnst_mat* newb, size_t *order, _cnst_mat** c);
    static void _solve_uxc();
};


#endif //CPPFOREST__CNST_MAT_H
