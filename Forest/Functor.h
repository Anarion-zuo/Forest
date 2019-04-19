#pragma once
class Functor
{
public:
	Functor();
	virtual ~Functor();

	virtual double f(double n) = 0;
	virtual double fp(double n) = 0;
};

