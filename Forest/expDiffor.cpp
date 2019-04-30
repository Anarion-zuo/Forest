#include "expDiffor.h"



expDiffor::expDiffor(cgNode* pp) : Diffor(pp)
{
}


expDiffor::~expDiffor()
{
}

cgNode* expDiffor::run()
{
	return p;
}

Diffor* expDiffor::clone(cgNode* node)
{
	Diffor* res = new expDiffor(node);
	return res;
}
