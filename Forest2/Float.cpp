#include "Float.h"
#include <cmath>

double Float::val() {
	return *p;
}

#pragma region operators
void Float::operator = (const Float& num) {
	if (p)* p = *num.p;
	else  p = new double(*num.p);
}

Float Float::operator- () {
	return Float(-*p);
}

Float Float::operator+ (const Float & num) const {
	return Float(*p + *num.p);
}

Float Float::operator- (const Float & num) const {
	return Float(*p - *num.p);
}

Float Float::operator* (const Float & num) const {
	return Float(*p * *num.p);
}

Float Float::operator/ (const Float & num) const {
	return Float(*p / *num.p);
}

Float Float::operator% (const Float & num) const {
	return Float(*p % *num.p);
}

bool Float::operator< (const Float & num) const {
	return *p < *num.p;
}

bool Float::operator> (const Float & num) const {
	return *p > * num.p;
}

bool Float::operator== (const Float & num) const {
	return *p == *num.p;
}

bool Float::operator!= (const Float & num) const {
	return *p != *num.p;
}

bool Float::operator<= (const Float & num) const {
	return *p <= *num.p;
}

bool Float::operator>= (const Float & num) const {
	return *p >= *num.p;
}
#pragma endregion

#pragma region special functions
Float Float::tenth(const Float & num) {
	return Float(*p * pow(10, *num.p));
}

#pragma endregion
