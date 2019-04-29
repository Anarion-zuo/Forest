#pragma once

#include <cmath>

class Functor
{	
public:
	Functor();
	virtual ~Functor();
	virtual double operator() (const double& n1, const double& n2) {};

	Functor* clone();
};

class addFunctor : public Functor
{
public:
	inline double operator() (const double& n1, const double& n2);
};

class subFunctor : public Functor
{
public:
	inline double operator() (const double& n1, const double& n2);
};

class mulFunctor : public Functor
{
public:
	inline double operator() (const double& n1, const double& n2);
};

class divFunctor : public Functor
{
public:
	inline double operator() (const double& n1, const double& n2);
};

class expFunctor : public Functor
{
public:
	inline double operator() (const double& n1, const double& n2);
};