#include "iArray.h"

bool iArray::equ(const double& a, const double& b) {
	return equ(a, b);
}

size_t iArray::size() const
{
	return p->size();
}

std::string iArray::to_csv() {
	return p->to_csv();
}

#pragma region structure operations
void iArray::resize(const size_t& n) {
	p->resize(n);
}
void iArray::push_back(const double& n) {
	p->push_back(n);
}
void iArray::push_at(const size_t& index, const double& n) {
	p->push_at(index, n);
}
void iArray::pop_back() {
	p->pop_back();
}
void iArray::pop_at(const size_t& index) {
	p->pop_at(index);
}
#pragma endregion
#pragma region operators
void iArray::operator=(const iArray& a)
{
	p = a.p;
}

iArray iArray::operator+(const iArray& a) const
{
	return *p + *a.p;
}

iArray iArray::operator+(const double& a) const
{
	return *p + a;
}

iArray iArray::operator-(const iArray& a) const
{
	return *p - *a.p;
}

iArray iArray::operator-(const double& a) const
{
	return *p - a;
}

iArray iArray::operator*(const iArray& a) const
{
	return *p * *a.p;
}

iArray iArray::operator*(const double& a) const
{
	return *p * a;
}

iArray iArray::operator/(const iArray& a) const
{
	return *p / *a.p;
}

iArray iArray::operator/(const double& a) const
{
	return *p / a;
}

double& iArray::operator[](const size_t& index)
{
	return (*p)[index];
}

bool iArray::operator==(const iArray& a) const
{
	return *p == *a.p;
}

bool iArray::operator!=(const iArray& a) const
{
	return *p != *a.p;
}
#pragma endregion

#pragma region statistical operations
double iArray::sum() const {
	return p->sum();
}

double iArray::nth_sum(const double& n) const
{
	return p->nth_sum(n);
}

double iArray::mean() const
{
	return p->mean();
}

double iArray::moment(const double& n) const
{
	return p->moment(n);
}

double iArray::magnitude() const
{
	return p->magnitude();
}

double iArray::norm(const double& n) const
{
	return p->norm(n);
}

double iArray::midval() const
{
	return p->midval();
}

double iArray::percentage(const double& a) const
{
	return p->percentage(a);
}

double iArray::mode() const
{
	return p->mode();
}

void iArray::centrolize()
{
	return p->centrolize();
}

double iArray::variance() {
	return p->variance();
}

void iArray::standardize()
{
	return p->standardize();
}
#pragma endregion
