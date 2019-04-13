#pragma once

class Float {
protected:
	double* p;
public:
	Float(const double& num = 0) : p(new double(num)) {}
	Float(const Float& num) : p(new double(*num.p)) {}
	Float(const Float* num) : p(new double(*num->p)) {}
	~Float() { delete p; }

	double val();

	void operator = (const Float& num);
	Float operator-();
	Float operator+(const Float& num) const;
	Float operator-(const Float& num) const;
	Float operator*(const Float& num) const;
	Float operator/(const Float& num) const;
	Float operator%(const Float& num) const;
	bool operator<(const Float& num) const;
	bool operator>(const Float& num) const;
	bool operator==(const Float& num) const;
	bool operator!=(const Float& num) const;
	bool operator<=(const Float& num) const;
	bool operator>=(const Float& num) const;
	Float tenth(const Float& num);
};