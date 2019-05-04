#include "cgNode.h"



cgNode* cgNode::clone_node(cgNode* node)
{
	if (!node)	return nullptr;
	if (node == nullNode::get())	return nullNode::get();
	Functor* fc = nullptr;
	Diffor* dc = nullptr;
	Trimor* tc = nullptr;
	if (node->func)	fc = node->func->clone();
	if (node->diffor) {
		dc = node->diffor->clone(nullptr);
	}
	if (node->trimor)	tc = node->trimor->clone(nullptr);
	cgNode* res = new cgNode(clone_node(node->left), clone_node(node->right), fc, dc, tc, node->val);
	res->diffor->p = res;
	res->trimor->p = res;
	return res;
}

cgNode::cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d, Trimor* t, const double& v = 0.0)
	: left(l), right(r), func(f), diffor(d), trimor(t), val(v) {}

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

