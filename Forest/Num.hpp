#pragma once

#include "Number.hpp"

template <class T> class Num {
private:
	Number<T>* p = nullptr;
public:
	Num(const Number<T>* pp) : p(pp) {}
	Num(const Num<T>& pp) : p(pp.p) {}
	~Num() { if (p) delete p; }

	inline Number<T>& operator-> () const {
		return *p;
	}
	//inline void operator= (const Number<T>* pp) {
	//	if (p)  delete p;
	//	p = pp;
	//}
	//inline void operator= (const Num<T>& pp) {
	//	if (p)  delete p;
	//	p = pp.p;
	//}
	inline Num<T> operator
};