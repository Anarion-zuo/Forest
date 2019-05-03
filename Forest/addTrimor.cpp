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
	if (cgNode::is_leaf(p->left) && p->left->is_const()) {
		if (equals(p->left->val, 0)) {
			cgNode* temp = p->left->right;
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
}
