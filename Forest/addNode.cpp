#include "addNode.h"

addNode::addNode(cgNode* l, cgNode* r) : cgNode(l, r, new addFunctor, new addDiffor(nullptr), 0) {
	diffor->p = this;
}

cgNode* addNode::clone()
{
	return new addNode(left->clone(), right->clone());
}