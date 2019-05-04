#include "expTrimor.h"



expTrimor::expTrimor(cgNode* pp) : Trimor(pp)
{
}


expTrimor::~expTrimor()
{
}

Trimor* expTrimor::clone(cgNode* pp)
{
	return new expTrimor(pp);
}

cgNode* expTrimor::run()
{
	p->left = p->left->trimor->run();
	p->right = p->right->trimor->run();

	if (is_n_node(p->right, 0)) {
		if (is_n_node(p->left, 0))	throw "Taking 0 to the 0th power.";
		cg::del_node(p->left);
		cg::del_node(p->right);
		p->left = nullptr;
		p->right = nullptr;
		p->func = nullptr;
		p->diffor = new constDiffor(p);
		p->trimor = new leafTrimor(p);
		p->val = 1;
	}
	else if (is_n_node(p->right, 1)) {
		cgNode* temp = p->left;
		p->left = temp->left;
		p->right = temp->right;
		p->func = temp->func;
		p->diffor = temp->diffor;
		p->diffor->p = p;
		p->trimor = temp->trimor;
		p->trimor->p = p;
		p->val = temp->val;
	}
	return p;
}
