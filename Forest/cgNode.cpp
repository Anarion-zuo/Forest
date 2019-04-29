#include "cgNode.h"



cgNode* cgNode::clone_node(cgNode* node)
{
	if (!node)	return nullptr;
	cgNode* res = new cgNode(clone_node(node->left), clone_node(node->right), node->func->clone(), node->diffor->clone(nullptr));
	res->diffor->p = res;
	return res;
}

cgNode::cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d) : left(l), right(r), func(f), diffor(d)
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
