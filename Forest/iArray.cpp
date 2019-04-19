#include "iArray.h"



void iArray::operator=(const iArray& a)
{
	p = a.p;
}

iArray iArray::operator+(const iArray& a)
{
	return *p + *a.p;
}

iArray iArray::operator+(const double& a)
{
	return *p + a;
}

iArray iArray::operator-(const iArray& a)
{
	return *p - *a.p;
}

iArray iArray::operator-(const double& a)
{
	return *p - a;
}

iArray iArray::operator*(const iArray& a)
{
	return *p * *a.p;
}

iArray iArray::operator*(const double& a)
{
	return *p * a;
}

iArray iArray::operator/(const iArray& a)
{
	return *p / *a.p;
}

iArray iArray::operator/(const double& a)
{
	return *p / a;
}

double& iArray::operator[](const size_t& index) const
{

}

bool iArray::operator==(const iArray& a) const
{

}

bool iArray::operator!=(const iArray& a) const
{

}
