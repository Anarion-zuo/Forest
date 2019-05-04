#include "addTrimor.h"



addTrimor::addTrimor(cgNode* pp) : Trimor(pp)
{
}


addTrimor::~addTrimor()
{
}

Trimor* addTrimor::clone(cgNode* pp)
{
	return new addTrimor(pp);
}

cgNode* addTrimor::run()
{
	p->left = p->left->trimor->run();
	p->right = p->right->trimor->run();
	if (is_n_node(p->left, 0)) {
		cgNode* temp = p->right;
		p->left = temp->left;
		p->right = temp->right;
		p->func = temp->func;
		p->diffor = temp->diffor;
		p->diffor->p = p;
		p->trimor = temp->trimor;
		p->trimor->p = p;
		p->val = temp->val;
	} else if (is_n_node(p->right, 0))
	{
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
