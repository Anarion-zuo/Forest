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

cg::cg(cgNode* r) : root(r)
{
}


cg::~cg()
{
	del_node(root);
}

void cg::diff(){
	Diffor::clear_delq();
	diff_node(root);
	Diffor::clear_delq();
}