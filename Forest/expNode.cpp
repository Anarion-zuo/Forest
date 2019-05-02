#include "expNode.h"

expNode::expNode(cgNode* l, cgNode* r) : cgNode(l, r, new expFunctor, new expDiffor(nullptr), 0) { diffor->p = this; }

cgNode* expNode::clone()
{
	return new expNode(left->clone(), right->clone());
}