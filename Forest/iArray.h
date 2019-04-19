#pragma once

#include "Array.h"

class iArray
{
private:
	Array* p = nullptr;
public:
	iArray() {}
	iArray(const size_t& s) : p(new Array(s)) {}
	iArray(const std::vector<double>& v) : p(new Array(v)) {}
	iArray(const Array& a) : p(new Array(a)) {}
	iArray(Array* a) : p(a) {}
	iArray(const iArray& a) : p(a.p) {}
	~iArray() { if (p)	delete p; }

	void operator= (const iArray& a);
	iArray operator+ (const iArray& a);
	iArray operator- (const iArray& a);
	iArray operator* (const iArray& a);
	iArray operator/ (const iArray& a);
	iArray operator+ (const double& a);
	iArray operator- (const double& a);
	iArray operator* (const double& a);
	iArray operator/ (const double& a);
	bool operator== (const iArray& a) const;
	inline bool operator!= (const iArray& a) const;
	double& operator[] (const size_t& index) const;

	inline double sum() const;
	inline double nth_sum(const double& n) const;
	inline double mean() const;
	inline double moment(const double& n) const;
	inline double magnitude() const;
	inline double norm(const double& n) const;
	inline double midval() const;
	inline double percentage(const double& a) const;
	inline double mode() const;
	inline void centrolize();
	inline double variance();
	inline void standardize();
};

