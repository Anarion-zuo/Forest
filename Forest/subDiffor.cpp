#include "subDiffor.h"



subDiffor::subDiffor(cgNode* pp) : Diffor(pp)
{
}


subDiffor::~subDiffor()
{
}

cgNode* subDiffor::run()
{
	p->left = p->left->diffor->run();
	p->right = p->right->diffor->run();
	return p;
}

Diffor* subDiffor::clone(cgNode* node)
{
	Diffor* res = new subDiffor(node);
	return res;
}
