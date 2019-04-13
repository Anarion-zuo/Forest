#pragma once

class Integer {
protected:
	long* p;
public:
	Integer(const long& num = 0) : p(new long(num)) {}
	Integer(const Integer& num) : p(new long(*num.p)) {}
	Integer(const Integer* num) : p(new long(*num->p)) {}
	~Integer() { delete p; }

	long val();

	void operator = (const Integer& num);
	Integer operator-();
	Integer operator+(const Integer& num) const;
	Integer operator-(const Integer& num) const;
	Integer operator*(const Integer& num) const;
	Integer operator/(const Integer& num) const;
	Integer operator%(const Integer& num) const;
	bool operator<(const Integer& num) const;
	bool operator>(const Integer& num) const;
	bool operator==(const Integer& num) const;
	bool operator!=(const Integer& num) const;
	bool operator<=(const Integer& num) const;
	bool operator>=(const Integer& num) const;
	Integer tenth(const Integer& num);
};