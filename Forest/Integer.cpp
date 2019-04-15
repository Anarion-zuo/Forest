#include "Integer.h"
#include <cmath>

long Integer::val() const {
	return val();
}

#pragma region operators
void Integer::operator = (const Number<long>* num) {
	if (p)* p = num.val();
	else  p = new long(num.val());
}

Number<long>* Integer::operator- () {
	return Integer(-val());
}

Number<long>* Integer::operator+ (const Number<long>* num) const {
	return Integer(val() + num->val());
}

Number<long>* Integer::operator- (const Number<long>* num) const {
	return Integer(val() - num->val());
}

Number<long>* Integer::operator* (const Number<long>* num) const {
	return Integer(val() * num->val());
}

Number<long>* Integer::operator/ (const Number<long>* num) const {
	return Integer(val() / num->val());
}

Number<long>* Integer::operator% (const Number<long>* num) const {
	return Integer(val() % num->val());
}

bool Integer::operator< (const Number<long>* num) const {
	return val() < num->val();
}

bool Integer::operator> (const Number<long>* num) const {
	return val() > num->val();
}

bool Integer::operator== (const Number<long>* num) const {
	return val() == num->val();
}

bool Integer::operator!= (const Number<long>* num) const {
	return val() != num->val();
}

bool Integer::operator<= (const Number<long>* num) const {
	return val() <= num->val();
}

bool Integer::operator>= (const Number<long>* num) const {
	return val() >= num->val();
}
#pragma endregion

#pragma region special functions
Number<long>* Integer::tenth(const Number<long>* num) {
	return Integer(val() * pow(10, num->val()));
}

#pragma endregion
