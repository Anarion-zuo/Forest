#include "divNode.h"

divNode::divNode(cgNode* l, cgNode* r) : cgNode(l, r, new divFunctor, new divDiffor(nullptr), 0) { diffor->p = this; }

cgNode* divNode::clone()
{
	return new divNode(left->clone(), right->clone());
}