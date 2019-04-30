#include "addDiffor.h"



addDiffor::addDiffor(cgNode* pp) : Diffor(pp)
{
}


addDiffor::~addDiffor()
{
}

cgNode* addDiffor::run()
{
	p->left = p->left->diffor->run();
	p->right = p->right->diffor->run();
	return p;
}

Diffor* addDiffor::clone(cgNode* node)
{
	Diffor* res = new addDiffor(node);
	return res;
}
