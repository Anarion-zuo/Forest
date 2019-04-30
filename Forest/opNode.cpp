#include "opNode.h"
#include "Functor.h"

// class addDiffor;
// class subDiffor;

addNode::addNode(cgNode* l, cgNode* r) : cgNode(l, r, new addFunctor, new addDiffor(nullptr), 0) { 
	diffor->p = this; 
}

cgNode* addNode::clone()
{
	return new addNode(left->clone(), right->clone());
}

subNode::subNode(cgNode* l, cgNode* r) : cgNode(l, r, new subFunctor, new subDiffor(nullptr), 0) { diffor->p = this; }

cgNode* subNode::clone()
{
	return new subNode(left->clone(), right->clone());
}

mulNode::mulNode(cgNode* l, cgNode* r) : cgNode(l, r, new mulFunctor, new mulDiffor(nullptr), 0) { diffor->p = this; }

cgNode* mulNode::clone()
{
	return new mulNode(left->clone(), right->clone());
}

divNode::divNode(cgNode* l, cgNode* r) : cgNode(l, r, new divFunctor, new divDiffor(nullptr), 0) { diffor->p = this; }

cgNode* divNode::clone()
{
	return new divNode(left->clone(), right->clone());
}

expNode::expNode(cgNode* l, cgNode* r) : cgNode(l, r, new expFunctor, new expDiffor(nullptr), 0) { diffor->p = this; }

cgNode* expNode::clone()
{
	return new expNode(left->clone(), right->clone());
}

