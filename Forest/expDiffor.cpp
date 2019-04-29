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
