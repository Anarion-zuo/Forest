#include "Matrix.h"

size_t Matrix::width() const {
	return c.size();
}

size_t Matrix::height() const {
	return _height;
}

Matrix::Matrix(const size_t& x, const size_t& y) : c(y, iArray(x, 0)), _height(x) {}

Matrix::~Matrix() {}

std::string Matrix::to_csv() {
	if (!(width() && height()))	throw "Trying to print null matrix.";
	std::string s;
	for (size_t i = 0; i < height(); ++i) {
		for (size_t j = 0; j < width(); ++j) {
			s += std::to_string(loc(i, j));
			if (j != width() - 1) {
				s += ',';
			}
			else {
				s += '\n';
			}
		}
	}
}

double& Matrix::loc(const size_t& x, const size_t& y)
{
	return c[y][x];
}

Matrix* Matrix::operator+(const Matrix& m)
{
	if (m.width() != width() || m.height() != height())  throw "Operation on matrices of different shape.";
	Matrix* p = new Matrix(height(), width());
	for (size_t i = 0; i < width(); ++i) {
		p->c[i] = m.c[i] + c[i];
	}
	return p;
}

