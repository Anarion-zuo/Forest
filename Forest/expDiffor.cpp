#include "expDiffor.h"



expDiffor::expDiffor(cgNode* pp) : Diffor(pp)
{
}


expDiffor::~expDiffor()
{
}

cgNode* expDiffor::run()
{
	cgNode* a = p->left, * b = p->right;
	p->diffor = new addDiffor(p);
	p->func = new addFunctor;
	p->left = new mulNode(
		b->clone(),
		new mulNode(
			new expNode(a->clone(), b->clone()),
			new lnNode(a->clone())
		)
	);
	p->right = 
		new mulNode(
			new mulNode(
				new expNode(a->clone(), new subNode(b->clone(), new constNode(1))),
				b->clone()
			),
			a->clone()
	);
	p->left->left = p->left->left->diffor->run();
	p->right->right = p->right->right->diffor->run();
	del_push_self();
	return p;
}

Diffor* expDiffor::clone(cgNode* node)
{
	Diffor* res = new expDiffor(node);
	return res;
}
