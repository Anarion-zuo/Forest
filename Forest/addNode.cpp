#include "addNode.h"

addNode::addNode(cgNode* l, cgNode* r) : cgNode(l, r, new addFunctor, new addDiffor(nullptr), new addTrimor(nullptr), 0) {
	diffor->p = this;
	trimor->p = this;
}

//cgNode* addNode::clone()
//{
//	cgNode* n1 = nullptr, * n2 = nullptr;
//	if (left)	n1 = left->clone();
//	if (right)	n2 = right->clone();
//	return new addNode(n1, n2);
//}