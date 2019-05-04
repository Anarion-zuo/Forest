#include "divNode.h"

divNode::divNode(cgNode* l, cgNode* r) : cgNode(l, r, new divFunctor, new divDiffor(nullptr), new divTrimor(nullptr), 0) {
	diffor->p = this;
	trimor->p = this;
}

//cgNode* divNode::clone()
//{
//	cgNode* n1 = nullptr, * n2 = nullptr;
//	if (left)	n1 = left->clone();
//	if (right)	n2 = right->clone();
//	return new divNode(n1, n2);
//}