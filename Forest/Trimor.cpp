#include "Trimor.h"



bool Trimor::is_n_node(cgNode* node, const double& n)
{
	if (cgNode::is_leaf(node) && node->is_const()) {
		return equals(node->val, n);
	}
	return false;
}

Trimor::Trimor(cgNode* pp) : p(pp)
{
}


Trimor::~Trimor()
{
}

Trimor* Trimor::clone(cgNode* pp)
{
	return new Trimor(pp);
}
