#pragma once

#include <cmath>

class Functor
{
private:
public:
	Functor();
	virtual ~Functor();
	virtual double operator() (const double& n1, const double& n2) { return 0.0; };

	virtual Functor* clone();
};

class addFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);

	Functor* clone();
};

class subFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
	Functor* clone();
};

class mulFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
	Functor* clone();
};

class divFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
	Functor* clone();
};

class expFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
	Functor* clone();
};

class varFunctor : public Functor
{
public:
// 	double operator() (const double& n1, const double& n2);
	Functor* clone();
};

class lnFunctor : public Functor
{
public:
	double operator() (const double& n1, const double& n2);
	Functor* clone();
};

class nullFunctor : public Functor {
private:
	nullFunctor() {}
	~nullFunctor() {}
	static nullFunctor* ins;
public:
	static nullFunctor* get();
	double operator() (const double& n1, const double& n2) { return 0.0; }
	Functor* clone() { return this; }
};