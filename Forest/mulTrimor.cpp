#include "mulTrimor.h"



mulTrimor::mulTrimor(cgNode* pp) : Trimor(pp)
{
}


mulTrimor::~mulTrimor()
{
}

Trimor* mulTrimor::clone(cgNode* pp)
{
	return new mulTrimor(pp);
}

cgNode* mulTrimor::run()
{
	if (p->left)	p->left = p->left->trimor->run();
	if (p->right)	p->right = p->right->trimor->run();

	if (is_n_node(p->left, 0) || is_n_node(p->right, 0))
	{
		cg::del_node(p->left);
		cg::del_node(p->right);
		p->left = nullptr;
		p->right = nullptr;
		p->func = nullptr;
		p->diffor = new constDiffor(p);
		p->trimor = new leafTrimor(p);
		p->val = 0;
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
	else if (is_n_node(p->left, 1)) {
		cgNode* temp = p->right;
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
