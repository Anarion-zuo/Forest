#include "mulNode.h"

mulNode::mulNode(cgNode* l, cgNode* r) : cgNode(l, r, new mulFunctor, new mulDiffor(nullptr), new mulTrimor(nullptr), 0) {
	diffor->p = this;
	trimor->p = this;
}

//cgNode* mulNode::clone()
//{
//	cgNode* n1 = nullptr, * n2 = nullptr;
//	if (left)	n1 = left->clone();
//	if (right)	n2 = right->clone();
//	return new mulNode(n1, n2);
//}