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
	*p = *this;
	return p;
}

double addFunctor::operator()(const double& n1, const double& n2)
{
	return n1 + n2;
}

double subFunctor::operator()(const double& n1, const double& n2)
{
	return n1 - n2;
}

double mulFunctor::operator()(const double& n1, const double& n2)
{
	return n1 * n2;
}

double divFunctor::operator()(const double& n1, const double& n2)
{
	return n1 / n2;
}

double expFunctor::operator()(const double& n1, const double& n2)
{
	return pow(n1, n2);
}


