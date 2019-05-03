#include "Trimor.h"



Trimor::Trimor(cgNode* pp) : p(pp)
{
}


Trimor::~Trimor()
{
}

Trimor* Trimor::clone(cgNode* pp)
{
	return new Trimor(pp);
}
