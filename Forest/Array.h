#pragma once
#include <vector>
#include <limits>
#include <string>

const double equ_tolerance = std::numeric_limits<double>::epsilon() * 10;

class Matrix;
class Array {
	friend class iArray;
private:
protected:
	std::vector<double> c;

	static inline bool equ(const double& a, const double& b);
public:
	Array() {}
	Array(const size_t& s, const size_t& n = 0) : c(s, n) {}
	Array(const std::vector<double>& v) : c(v) {}
	Array(const Array& a) : c(a.c) {}
	Array(const Array* a) : c(a->c) {}
	virtual ~Array() {}

	inline size_t size() const;

	std::string to_csv();

	void resize(const size_t& n);
	void push_back(const double& n);
	void push_at(const size_t& index, const double& n);
	void pop_back();
	void pop_at(const size_t& index);

	void operator= (const std::vector<double>& v);
	void operator= (const Array& a);
	Array* operator+ (const Array& a) const;
	Array* operator- (const Array& a) const;
	Array* operator* (const Array& a) const;
	Array* operator/ (const Array& a) const;
	Array* operator+ (const double& a) const;
	Array* operator- (const double& a) const;
	Array* operator* (const double& a) const;
	Array* operator/ (const double& a) const;
	bool operator== (const Array& a) const;
	bool operator!= (const Array& a) const;
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