#include "Array.h"

size_t Array::size() const {
	return c.size();
}

std::string Array::to_csv() {
	if (!size())  throw "Trying to print null array.";
	std::string p;
	for (size_t i = 0; i < size(); ++i) {
		p += std::to_string(c[i]);
		if (i != size() - 1) {
			p += ',';
		}
	}
	return p;
}

#pragma region structure operations
void Array::resize(const size_t& n) {
	c.resize(n);
}

void Array::push_back(const double& n) {
	c.push_back(n);
}

bool Array::equ(const double& a, const double& b)
{
	return abs(a - b) <= equ_tolerance;
}

void Array::push_at(const size_t& index, const double& n) {
	c.insert(c.begin() + index, n);
}

void Array::pop_back() {
	c.pop_back();
}

void Array::pop_at(const size_t& index)
{
	c.erase(c.begin() + index);
}

#pragma endregion
#pragma region basic numerical operations
void Array::operator= (const Array& a) {
	c = a.c;
}
void Array::operator= (const std::vector<double>& v) {
	c = v;
}

double& Array::operator[] (const size_t& index) {
	return c[index];
}
Array* Array::operator+(const Array& a) const
{
	if (size() != a.size())  throw "Array operation with inconsistent length.";
	Array* p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
		p->c[i] = c[i] + a.c[i];
	}
	return p;
}

Array* Array::operator+(const double& a) const
{
	Array * p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
		p->c[i] = c[i] + a;
	}
	return p;
}

Array* Array::operator-(const Array& a) const
{
	if (size() != a.size())  throw "Array operation with inconsistent length.";
	Array * p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
		p->c[i] = c[i] - a.c[i];
	}
	return p;
}

Array* Array::operator-(const double& a) const
{
	Array* p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
		p->c[i] = c[i] - a;
	}
	return p;
}

Array* Array::operator*(const Array& a) const
{
	if (size() != a.size())  throw "Array operation with inconsistent length.";
	Array * p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
		p->c[i] = c[i] * a.c[i];
	}
	return p;
}

Array* Array::operator*(const double& a) const
{
	Array* p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
		p->c[i] = c[i] * a;
	}
	return p;
}

Array* Array::operator/(const Array& a) const
{
	if (size() != a.size())  throw "Array operation with inconsistent length.";
	Array * p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
		p->c[i] = c[i] / a.c[i];
	}
	return p;
}

Array* Array::operator/(const double& a) const
{
	Array* p = new Array(size());
	for (size_t i = 0; i < size(); ++i) {
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
	for (size_t i = 0; i < size(); ++i) {
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
	for (size_t i = 0; i < size(); ++i) {
		res += c[i];
	}
	return res;
}

double Array::nth_sum(const double& n) const
{
	double res = 0;
	for (size_t i = 0; i < size(); ++i) {
		res += pow(c[i], n);
	}
	return res;
}

double Array::mean() const
{
	return sum() / size();
}

double Array::moment(const double& n) const
{
	return nth_sum(n) / size();
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
	for (size_t i = 0; i < size(); i++) {
		c[i] -= m;
	}
}

double Array::variance() {
	double m = mean(), res = 0;
	for (size_t i = 0; i < size(); i++) {
		res += pow((c[i] - m), 2);
	}
	return res;
}

void Array::standardize()
{
	centrolize();
	double v = sqrt(variance());
	for (size_t i = 0; i < size(); i++) {
		c[i] /= v;
	}
}

#pragma endregion
