#include "subTrimor.h"



subTrimor::subTrimor(cgNode* pp) : Trimor(pp)
{
}


subTrimor::~subTrimor()
{
}

Trimor* subTrimor::clone(cgNode* pp)
{
	return new subTrimor(pp);
}

cgNode* subTrimor::run()
{
	p->left = p->left->trimor->run();
	p->right = p->right->trimor->run();
	if (cgNode::is_leaf(p->right) && p->right->is_const())
	{
		if (equals(p->right->val, 0)) {
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
	}
	return p;
}
