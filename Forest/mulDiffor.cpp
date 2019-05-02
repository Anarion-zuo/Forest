#include "mulDiffor.h"



mulDiffor::mulDiffor(cgNode* pp) : Diffor(pp)
{
}


mulDiffor::~mulDiffor()
{
}

cgNode* mulDiffor::run() {
	delete p->func;
	p->func = new addFunctor;
	p->diffor = new addDiffor(p);
	cgNode* a = p->left, * b = p->right;
	p->left = new mulNode(a, b);
	p->right = new mulNode(a->clone(), b->clone());
	p->left->left = p->left->left->diffor->run();
	p->right->right = p->right->right->diffor->run();
	del_push_self();
	return p;
}

Diffor* mulDiffor::clone(cgNode* node)
{
	Diffor* res = new mulDiffor(node);
	return res;
}
