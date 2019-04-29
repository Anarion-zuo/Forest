#pragma once
class Functor
{
protected:
	Functor();
public:
	virtual ~Functor();

	virtual double f(double n1, double n2) = 0;
	virtual Functor* get() = 0;
};

