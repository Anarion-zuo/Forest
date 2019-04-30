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

void cg::trim_node(cgNode* node)
{
	if (!node)	return;
	if (node->left)	node->left->trim();
	if (node->right)	node->right->trim();
	node->trim();
}

double cg::compute(cgNode* node)
{
	if (cgNode::is_leaf(node))	return node->val;
	node->val = node->func->operator()(compute(node->left), compute(node->right));
	return node->val;
}

bool cg::is_var(cgNode* node)
{
	for (size_t i = 0; i < varq.size(); ++i) {
		if (varq[i] == node)	return true;
	}
	return false;
}

void cg::trim()
{
	trim_node(root);
}

void cg::find_vars()
{
	find_var_node(root, varq);
}

void cg::refresh_var(cgNode* node)
{
	if (!node)	return;
	if (cgNode::is_leaf(node)) {
		if (!node->is_const()) {
			if (!is_var(node)) {
				varq.push_back(node);
			}
		}
	}
	refresh_var(node->left);
	refresh_var(node->right);
}

cg::cg(cgNode* r) : root(r)
{
	refresh_var(root);
}


cg::~cg()
{
	del_node(root);
// 	delete var_id;
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
	varDiffor::clear_map();
	cgNode* r = root->clone();
	r = r->diffor->run();
	dcg* res = new dcg(r, varDiffor::get_map());
	varDiffor::clear_map();
	return res;
}