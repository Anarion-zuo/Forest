#include "Integer.h"
#include <cmath>

long Integer::val() {
	return *p;
}

#pragma region operators
void Integer::operator = (const Integer& num) {
	if (p)* p = *num.p;
	else  p = new long(*num.p);
}

Integer Integer::operator- () {
	return Integer(-*p);
}

Integer Integer::operator+ (const Integer & num) const {
	return Integer(*p + *num.p);
}

Integer Integer::operator- (const Integer & num) const {
	return Integer(*p - *num.p);
}

Integer Integer::operator* (const Integer & num) const {
	return Integer(*p * *num.p);
}

Integer Integer::operator/ (const Integer & num) const {
	return Integer(*p / *num.p);
}

Integer Integer::operator% (const Integer& num) const {
	return Integer(*p % *num.p);
}

bool Integer::operator< (const Integer & num) const {
	return *p < *num.p;
}

bool Integer::operator> (const Integer & num) const {
	return *p > * num.p;
}

bool Integer::operator== (const Integer & num) const {
	return *p == *num.p;
}

bool Integer::operator!= (const Integer & num) const {
	return *p != *num.p;
}

bool Integer::operator<= (const Integer & num) const {
	return *p <= *num.p;
}

bool Integer::operator>= (const Integer & num) const {
	return *p >= *num.p;
}
#pragma endregion

#pragma region special functions
Integer Integer::tenth(const Integer& num) {
	return Integer(*p * pow(10, *num.p));
}

#pragma endregion
