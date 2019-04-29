#pragma once

#include <cmath>

class Functor
{
private:
public:
	Functor();
	virtual ~Functor();
	virtual double operator() (const double& n1, const double& n2) { return 0.0; };

	Functor* clone();
};

class addFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
};

class subFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
};

class mulFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
};

class divFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
};

class expFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
};

class varFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
};