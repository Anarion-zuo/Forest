#pragma once

#include "iArray.h"

class iArray;
class Matrix
{
private:
	std::vector<iArray> c;
	size_t _height;
public:
	Matrix(const size_t& x, const size_t& y);
	~Matrix();

	inline size_t width() const;
	inline size_t height() const;

	std::string to_csv();

	inline double& loc(const size_t& x, const size_t& y);
	Matrix* operator+ (const Matrix& m);
	Matrix* operator- (const Matrix& m);
	Matrix* operator* (const Matrix& m);
	Matrix* operator/ (const Matrix& m);
	Matrix* operator+ (const double& n);
	Matrix* operator- (const double& n);
	Matrix* operator* (const double& n);
	Matrix* operator/ (const double& n);
};

class Identity_Matrix : public Matrix {
public:
	Identity_Matrix(const size_t& s);
};