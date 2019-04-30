#include "cg.h"



void cg::del_node(cgNode* node)
{
	if (!node)	return;
	if (node->left)	del_node(node->left);
	if (node->right)	del_node(node->right);
	delete node;
}

void cg::diff_node(cgNode*& node)
{
	if (!node)	return;
	node = node->diffor->run();
}

void cg::find_var_node(cgNode* node, std::vector<cgNode*>& qq)
{
	if (!node)	return;
	if (cgNode::is_leaf(node)) {
		if (!node->is_const()) {
			qq.push_back(node);
		}
		return;
	}
	find_var_node(node->right, qq);
	find_var_node(node->left, qq);
}

double cg::compute(cgNode* node)
{
	if (cgNode::is_leaf(node))	return node->val;
	node->val = node->func->operator()(compute(node->left), compute(node->right));
	return node->val;
}

void cg::find_vars()
{
	find_var_node(root, varq);
}

cg::cg(cgNode* r) : root(r)
{
}


cg::~cg()
{
	del_node(root);
}

cg* cg::clone()
{
	return new cg(root->clone());
}

void cg::diff(){
	Diffor::clear_delq();
	if (!root)	return;
	root = root->diffor->run();
	Diffor::clear_delq();
}

double cg::run(const std::vector<double>& vallist)
{
	if (vallist.size() != varq.size())	throw "Input independent variable values error, inconsistence.";
	for (size_t i = 0; i < varq.size(); ++i) {
		varq[i]->val = vallist[i];
	}
	return compute(root);
}

dcg* cg::diff_graph()
{
	dcg* res = new dcg(root->clone());
	res->diff();
	return res;
}