#include "mulNode.h"

mulNode::mulNode(cgNode* l, cgNode* r) : cgNode(l, r, new mulFunctor, new mulDiffor(nullptr), 0) { diffor->p = this; }

cgNode* mulNode::clone()
{
	return new mulNode(left->clone(), right->clone());
}