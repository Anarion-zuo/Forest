#include "Functor.h"



Functor::Functor()
{
}

Functor::~Functor()
{
}

Functor* Functor::clone()
{
	Functor* p = new Functor();
	return p;
}

double addFunctor::operator()(const double& n1, const double& n2)
{
	return n1 + n2;
}

Functor* addFunctor::clone()
{
	Functor* p = new addFunctor();
	return p;
}

double subFunctor::operator()(const double& n1, const double& n2)
{
	return n1 - n2;
}

Functor* subFunctor::clone()
{
	Functor* p = new subFunctor();
	return p;
}

double mulFunctor::operator()(const double& n1, const double& n2)
{
	return n1 * n2;
}

Functor* mulFunctor::clone()
{
	Functor* p = new mulFunctor();
	return p;
}

double divFunctor::operator()(const double& n1, const double& n2)
{
	return n1 / n2;
}

Functor* divFunctor::clone()
{
	Functor* p = new divFunctor();
	return p;
}

double expFunctor::operator()(const double& n1, const double& n2)
{
	return pow(n1, n2);
}


Functor* expFunctor::clone()
{
	Functor* p = new expFunctor();
	return p;
}

Functor* varFunctor::clone()
{
	Functor* p = new varFunctor();
	return p;
}

double lnFunctor::operator()(const double& n1, const double& n2 = 0)
{
	return log(n1);
}

Functor* lnFunctor::clone()
{
	Functor* p = new lnFunctor();
	return p;
}

nullFunctor* nullFunctor::ins = new nullFunctor;

nullFunctor* nullFunctor::get()
{
	return ins;
}
