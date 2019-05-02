#include "subNode.h"

subNode::subNode(cgNode* l, cgNode* r) : cgNode(l, r, new subFunctor, new subDiffor(nullptr), 0) { diffor->p = this; }

cgNode* subNode::clone()
{
	return new subNode(left->clone(), right->clone());
}