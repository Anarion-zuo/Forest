#pragma once

#include "Number.hpp"

class Integer : public Number<long> {
protected:
	long* p;
public:
	Integer(const long& num = 0) : p(new long(num)) {}
	Integer(const Integer& num) : p(new long(*num.p)) {}
	Integer(const Integer* num) : p(new long(*num->p)) {}
	~Integer() { delete p; }

	//inline long val() const;

	void operator = (const Number<long>* num);
	Number<long>* operator-();
	Number<long>* operator+(const Number<long>* num) const;
	Number<long>* operator-(const Number<long>* num) const;
	Number<long>* operator*(const Number<long>* num) const;
	Number<long>* operator/(const Number<long>* num) const;
	Number<long>* operator%(const Number<long>* num) const;
	bool operator<(const Number<long>* num) const;
	bool operator>(const Number<long>* num) const;
	bool operator==(const Number<long>* num) const;
	bool operator!=(const Number<long>* num) const;
	bool operator<=(const Number<long>* num) const;
	bool operator>=(const Number<long>* num) const;
	Number<long>* tenth(const Number<long>* num);
};