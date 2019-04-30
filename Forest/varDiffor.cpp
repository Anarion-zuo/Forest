#include "varDiffor.h"



varDiffor::varDiffor(cgNode* pp) : Diffor(pp)
{
}


varDiffor::~varDiffor()
{
}

cgNode* varDiffor::run()
{
	return p;
}

Diffor* varDiffor::clone(cgNode* node)
{
	Diffor* res = new varDiffor(node);
	return res;
}
