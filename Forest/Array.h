#pragma once
#include <vector>
#include <limits>

const double equ_tolerance = std::numeric_limits<double>::epsilon() * 10;

class Array {
private:
	struct {

	};
protected:
	double* c = nullptr;
	size_t size = 0;
	size_t length = 0;

	inline void double_size();
	void mover(const size_t& index, const size_t& step);
	static inline bool equ(const double& a, const double& b);
public:
	Array(const size_t& s) : c(new double[s] {0}), size(s), length(size) {}
	Array(const std::vector<double>& v) : c(new double[v.size()]), size(v.size()), length(size) {
		for (size_t i = 0; i < size; ++i) {
			c[i] = v[i];
		}
	}
	Array(const Array& a) : c(new double[a.size]), size(a.size), length(size) {
		for (size_t i = 0; i < size; ++i) {
			c[i] = a.c[i];
		}
	}
	~Array() { if (c)  delete[] c; }

	void resize(const size_t& n);
	void push_back(const double& n);
	void push_at(const size_t& index, const double& n);
	void pop_back();
	void pop_at(const size_t& index);

	void operator= (const std::vector<double>& v);
	void operator= (const Array& a);
	Array& operator+ (const Array& a) const;
	Array& operator- (const Array& a) const;
	Array& operator* (const Array& a) const;
	Array& operator/ (const Array& a) const;
	Array& operator+ (const double& a) const;
	Array& operator- (const double& a) const;
	Array& operator* (const double& a) const;
	Array& operator/ (const double& a) const;
	bool operator== (const Array& a) const;
	inline bool operator!= (const Array& a) const;
	double& operator[] (const size_t& index) const;

	double sum() const;
	double nth_sum(const double& n) const;
	inline double mean() const;
	inline double moment(const double& n) const;
	inline double magnitude() const;
	inline double norm(const double& n) const;
	double midval() const;
	double percentage(const double& a) const;
	double mode() const;
	void centrolize();
	void standardize();
};