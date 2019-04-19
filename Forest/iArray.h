#pragma once

#include "Array.h"

class iArray
{
private:
	Array* p = nullptr;
	static inline bool equ(const double& a, const double& b);
public:
	iArray() {}
	iArray(const size_t& s, const size_t& n = 0) : p(new Array(s, n)) {}
	iArray(const std::vector<double>& v) : p(new Array(v)) {}
	iArray(const Array& a) : p(new Array(a)) {}
	iArray(Array* a) : p(a) {}
	iArray(const iArray& a) : p(a.p) {}
	~iArray() { if (p)	delete p; }

	size_t size() const;

	std::string to_csv();

	void resize(const size_t& n);
	void push_back(const double& n);
	void push_at(const size_t& index, const double& n);
	void pop_back();
	void pop_at(const size_t& index);

	void operator= (const iArray& a);
	iArray operator+ (const iArray& a) const;
	 iArray operator- (const iArray& a) const;
	 iArray operator* (const iArray& a) const;
	 iArray operator/ (const iArray& a) const;
	 iArray operator+ (const double& a) const;
	 iArray operator- (const double& a) const;
	 iArray operator* (const double& a) const;
	 iArray operator/ (const double& a) const;
	 bool operator== (const iArray& a) const;
	 bool operator!= (const iArray& a) const;
	 double& operator[] (const size_t& index);

	 double sum() const;
	 double nth_sum(const double& n) const;
	 double mean() const;
	 double moment(const double& n) const;
	 double magnitude() const;
	 double norm(const double& n) const;
	 double midval() const;
	 double percentage(const double& a) const;
	 double mode() const;
	 void centrolize();
	 double variance();
	 void standardize();
};

