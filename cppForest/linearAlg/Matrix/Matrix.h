//
// Created by anarion on 19-5-31.
//

#ifndef CPPFOREST_MATRIX_H
#define CPPFOREST_MATRIX_H

#include "../Array/Array.h"
#include "Titles.h"

class Matrix {
protected:
    std::vector<Array*> _c;  // column-wise
public:
    Matrix(size_t h, size_t w, double a);
    Matrix(const std::vector<Array*>& c);
    virtual ~Matrix();
    Matrix* clone();

    // size
    size_t width();
    size_t height();
    bool empty();

    // statistics
    Array* sum();
    Array* prod();
    Array* mean();
    Array* moment(size_t n);
    Array* nth_item(size_t n);
    Array* most_frequent();

    // search
    double& loc(size_t i, size_t j);

    // structure operations
    void hstack(Matrix* m);
    void vstack(Matrix* m);
    Matrix* transpose();
    Matrix* partial(size_t x1, size_t y1, size_t x2, size_t y2);

    // arithmatic operations
    static Matrix* add(Matrix* m1, Matrix* m2);
    static Matrix* sub(Matrix* m1, Matrix* m2);
    static Matrix* mul(Matrix* m1, Matrix* m2);


    // Strassen
private:
    static void _fill_0s(Matrix* m);
    static std::vector<Matrix*>* _divide_four(Matrix* m);
    static Matrix* _ass_four(Matrix* c11, Matrix* c12, Matrix* c21, Matrix* c22);
    static Matrix* _shrink(Matrix* m);

public:
    static Matrix* _strassen_mul(Matrix* m1, Matrix* m2);
public:
    static Matrix* slow_mul(Matrix* m1, Matrix* m2);
    static Matrix* fast_mul(Matrix* m1, Matrix* m2);

    std::string to_string();
};


#endif //CPPFOREST_MATRIX_H
