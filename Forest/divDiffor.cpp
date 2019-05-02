#include "divDiffor.h"



divDiffor::divDiffor(cgNode* pp) : Diffor(pp)
{
}


divDiffor::~divDiffor()
{
}

cgNode* divDiffor::run()
{
	clear_delq();
	cgNode* a = p->left, * b = p->right;
	cgNode* l = new subNode(
		new mulNode(a, b),
		new mulNode(a->clone(), b->clone())
	);
	l->left->left = l->left->left->diffor->run();
	l->right->right = l->right->right->diffor->run();
	p->left = l;
	p->right = new expNode(b->clone(), new constNode(2));
	return p;
}

Diffor* divDiffor::clone(cgNode* node)
{
	Diffor* res = new divDiffor(node);
	return res;
}
