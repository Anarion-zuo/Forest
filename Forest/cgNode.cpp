#include "cgNode.h"



cgNode* cgNode::clone_node(cgNode* node)
{
	if (!node)	return nullptr;
	cgNode* res = new cgNode(clone_node(node->left), clone_node(node->right), node->func->clone(), node->diffor->clone(nullptr), val);
	res->diffor->p = res;
	return res;
}

cgNode::cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d, const double& v = 0.0) : left(l), right(r), func(f), diffor(d), val(v)
{
}

cgNode::~cgNode() {
	if (func)	delete func;
	if (diffor)	delete diffor;
}

cgNode* cgNode::clone()
{
	return clone_node(this);
}

bool cgNode::is_leaf(cgNode* node)
{
	return !(node->left || node->right);
}

void cgNode::set_val(const double& d)
{
	val = d;
}

bool cgNode::is_const()
{
	return false;
}
