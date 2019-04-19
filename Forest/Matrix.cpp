#include "Matrix.h"



Matrix::Matrix(const size_t& x, const size_t y)
	: height(x), width(y), c(new Array[y])
{
	for (size_t i = 0; i < width; ++i) {
		c[i].resize(x);
	}
}


Matrix::~Matrix()
{
	if (c)  delete[] c;
}

double& Matrix::loc(const size_t& x, const size_t& y)
{
	return c[y][x];
}

Matrix& Matrix::Matrix::operator+(const Matrix& m)
{
	if (m.width != width || m.height != height)  throw "Operation on matrices of different shape.";
	Matrix* p = new Matrix(height, width);
	for (size_t i = 0; i < width; ++i) {
		Array* t = &(c[i] + m.c[i]);
		p->c[i] = *new Array(*t);
		delete t;
	}
	return *p;
}

