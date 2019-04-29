#include "constDiffor.h"

constDiffor::constDiffor(cgNode* pp) : Diffor(pp)
{
}


constDiffor::~constDiffor()
{
}

cgNode* constDiffor::run()
{
	p->set_val(0.0);
	return p;
}
