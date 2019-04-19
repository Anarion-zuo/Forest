#pragma once

#include "Array.h"

class Matrix
{
private:
	Array* c = nullptr;
	size_t width = 0, height = 0;
public:
	Matrix(const size_t& x, const size_t y);
	~Matrix();

	double& loc(const size_t& x, const size_t& y);
	Matrix& operator+ (const Matrix& m);
	Matrix& operator- (const Matrix& m);
	Matrix& operator* (const Matrix& m);
	Matrix& operator/ (const Matrix& m);
	Matrix& operator+ (const double& n);
	Matrix& operator- (const double& n);
	Matrix& operator* (const double& n);
	Matrix& operator/ (const double& n);
};

class Identity_Matrix : public Matrix {
public:
	Identity_Matrix(const size_t& s);
};