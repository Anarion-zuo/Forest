#include "expNode.h"

expNode::expNode(cgNode* l, cgNode* r) : cgNode(l, r, new expFunctor, new expDiffor(nullptr), new expTrimor(nullptr), 0) {
	diffor->p = this;
	trimor->p = this;
}

//cgNode* expNode::clone()
//{
//	cgNode* n1 = nullptr, * n2 = nullptr;
//	if (left)	n1 = left->clone();
//	if (right)	n2 = right->clone();
//	return new expNode(n1, n2);
//}