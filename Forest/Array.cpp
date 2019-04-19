#include "Array.h"

std::string Array::to_csv() {
	if (!length)  throw "Trying to print null array.";
	std::string p;
	for (size_t i = 0; i < length; ++i) {
		p += std::to_string(c[i]);
		if (i != length - 1) {
			p += ',';
		}
	}
	return p;
}

#pragma region structure operations
void Array::resize(const size_t& n) {
	double* cc = new double[n];
	size_t nn = n < size ? n : size;
	for (size_t i = 0; i < nn; i++) {
		cc[i] = c[i];
	}
	if (nn > size) {
		for (size_t i = 0; i < size; ++i)
		{
			cc[i + nn] = 0;
		}
	}
	delete[] c;
	c = cc;
	if (size > n) {
		length = n;
	}
	size = n;
}

void Array::double_size() {
	resize(2 * size);
}

void Array::push_back(const double& n) {
	if ((length + 1) >= size) {
		double_size();
	}
	c[length] = n;
	length++;
}

void Array::mover(const size_t& index, const size_t& step) {
	if (index > length || length + step >= size) {
		throw "Array operation out of range.";
	}
	length += step;
	double* cc = new double[length - index];
	for (size_t i = 0; i < length - index; ++i) {
		cc[i] = c[index + i];
	}
	for (size_t i = 0; i < step; ++i) {
		c[index + step + i] = cc[i];
	}
	delete[] cc;
}

bool Array::equ(const double& a, const double& b)
{
	return abs(a - b) <= equ_tolerance;
}

void Array::push_at(const size_t& index, const double& n) {
	if ((length + 1) >= size) {
		double_size();
	}
	mover(index, 1);
	c[index] = n;
}

void Array::pop_back() {
	if ((length - 1) * 3 <= size) {
		resize(size / 3 + 1);
	}
	length--;
}

void Array::pop_at(const size_t& index)
{

}

#pragma endregion
#pragma region basic numerical operations
void Array::operator= (const Array& a) {
	if (c)  delete[] c;
	c = new double[a.length];
	for (size_t i = 0; i < a.size; ++i) {
		c[i] = a.c[i];
	}
	size = a.length;
	length = size;
}
void Array::operator= (const std::vector<double>& v) {
	if (c)  delete[] c;
	c = new double[v.size()];
	for (size_t i = 0; i < v.size(); ++i) {
		c[i] = v[i];
	}
	size = v.size();
	length = size;
}

double& Array::operator[] (const size_t& index) const {
	return c[index];
}
Array* Array::operator+(const Array& a) const
{
	if (length != a.length)  throw "Array operation with inconsistent length.";
	Array* p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] + a.c[i];
	}
	return p;
}

Array* Array::operator+(const double& a) const
{
	Array * p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] + a;
	}
	return p;
}

Array* Array::operator-(const Array& a) const
{
	if (length != a.length)  throw "Array operation with inconsistent length.";
	Array * p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] - a.c[i];
	}
	return p;
}

Array* Array::operator-(const double& a) const
{
	Array* p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] - a;
	}
	return p;
}

Array* Array::operator*(const Array& a) const
{
	if (length != a.length)  throw "Array operation with inconsistent length.";
	Array * p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] * a.c[i];
	}
	return p;
}

Array* Array::operator*(const double& a) const
{
	Array* p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] * a;
	}
	return p;
}

Array* Array::operator/(const Array& a) const
{
	if (length != a.length)  throw "Array operation with inconsistent length.";
	Array * p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] / a.c[i];
	}
	return p;
}

Array* Array::operator/(const double& a) const
{
	Array* p = new Array(length);
	for (size_t i = 0; i < length; ++i) {
		p->c[i] = c[i] / a;
	}
	return p;
}

bool Array::operator!=(const Array& a) const
{
	return this->operator!= (a);
}

bool Array::operator==(const Array& a) const
{
	for (size_t i = 0; i < length; ++i) {
		if (!equ(c[i], a.c[i])) {
			return false;
		}
	}
	return true;
}
#pragma endregion
#pragma region statistical operations
double Array::sum() const {
	double res = 0;
	for (size_t i = 0; i < length; ++i) {
		res += c[i];
	}
	return res;
}

double Array::nth_sum(const double& n) const
{
	double res = 0;
	for (size_t i = 0; i < length; ++i) {
		res += pow(c[i], n);
	}
	return res;
}

double Array::mean() const
{
	return sum() / length;
}

double Array::moment(const double& n) const
{
	return nth_sum(n) / length;
}

double Array::magnitude() const
{
	return sqrt(nth_sum(2));
}

double Array::norm(const double& n) const
{
	return pow(nth_sum(2), 1 / n);
}

double Array::midval() const
{
	return 0;
}

double Array::percentage(const double& a) const
{
	return 0;
}

double Array::mode() const
{
	return 0;
}

void Array::centrolize()
{
	double m = mean();
	for (size_t i = 0; i < length; i++) {
		c[i] -= m;
	}
}

double Array::variance() {
	double m = mean(), res = 0;
	for (size_t i = 0; i < length; i++) {
		res += pow((c[i] - m), 2);
	}
	return res;
}

void Array::standardize()
{
	centrolize();
	double v = sqrt(variance());
	for (size_t i = 0; i < length; i++) {
		c[i] /= v;
	}
}

#pragma endregion
