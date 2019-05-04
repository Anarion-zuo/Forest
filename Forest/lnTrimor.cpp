#include "lnTrimor.h"



lnTrimor::lnTrimor(cgNode* pp) : Trimor(pp)
{
}


lnTrimor::~lnTrimor()
{
}

Trimor* lnTrimor::clone(cgNode* pp)
{
	return new lnTrimor(pp);
}

cgNode* lnTrimor::run()
{
	if (is_n_node(p, 0))	throw "Logarithm out of range.";
	return p;
}
