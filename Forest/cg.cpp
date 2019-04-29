#include "cg.h"



void cg::del_node(cgNode* node)
{
	if (node->left)	delete node->left;
	if (node->right)	delete node->right;
	delete node;
}

void cg::diff_node(cgNode*& node)
{
	if (!node)	return;
	Diffor* temp = node->diffor;
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

}