#include "divDiffor.h"



divDiffor::divDiffor(cgNode* pp) : Diffor(pp)
{
}


divDiffor::~divDiffor()
{
}

cgNode* divDiffor::run()
{
	return p;
}

Diffor* divDiffor::clone(cgNode* node)
{
	Diffor* res = new divDiffor(node);
	return res;
}
