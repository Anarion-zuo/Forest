#pragma once

#include "OP_Functor.h"

class Add_Functor : public OP_Functor {
private:
	static Functor* p;
protected:
	Add_Functor() {}
public:
	double f(double n1, double n2);
	Functor* get();
};

class Sub_Functor : public OP_Functor {
private:
	static Functor* p;
protected:
	Sub_Functor() {}
public:
	double f(double n1, double n2);
	Functor* get();
};