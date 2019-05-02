#include "lnNode.h"



lnNode::lnNode(cgNode* node) : cgNode(node, nullNode::get(), new lnFunctor, new lnDiffor(nullptr), 0)
{
	diffor->p = this;
}


lnNode::~lnNode()
{
}

cgNode* lnNode::clone()
{
	return new lnNode(left->clone());
}
