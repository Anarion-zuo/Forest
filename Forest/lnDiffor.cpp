#include "lnDiffor.h"



lnDiffor::lnDiffor(cgNode* pp) : Diffor(pp)
{
}


lnDiffor::~lnDiffor()
{
}

Diffor* lnDiffor::clone(cgNode* node)
{
	Diffor* res = new lnDiffor(node);
	return res;
}

cgNode* lnDiffor::run()
{
	delete p->func;
	p->diffor = new divDiffor(p);
	p->func = new divFunctor;
	cgNode* temp = p->left;
	p->left = new constNode(1);
	p->right = temp->diffor->run();
	del_push_self();
	return p;
}
