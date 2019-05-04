#include "subNode.h"

subNode::subNode(cgNode* l, cgNode* r) : cgNode(l, r, new subFunctor, new subDiffor(nullptr), new subTrimor(nullptr), 0) {
	diffor->p = this;
	trimor->p = this;
}

//cgNode* subNode::clone()
//{
//	cgNode* n1 = nullptr, * n2 = nullptr;
//	if (left)	n1 = left->clone();
//	if (right)	n2 = right->clone();
//	return new subNode(n1, n2);
//}