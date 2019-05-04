#include "leafTrimor.h"



leafTrimor::leafTrimor(cgNode* pp) : Trimor(pp)
{
}


leafTrimor::~leafTrimor()
{
}

Trimor* leafTrimor::clone(cgNode* pp)
{
	return new leafTrimor(pp);
}

cgNode* leafTrimor::run()
{
	return p;
}
