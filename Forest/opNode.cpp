#include "opNode.h"
#include "Functor.h"

// class addDiffor;
// class subDiffor;
addNode::addNode(cgNode* l, cgNode* r) : cgNode(l, r, new addFunctor, new addDiffor(this)) {}
subNode::subNode(cgNode* l, cgNode* r) : cgNode(l, r, new subFunctor, new subDiffor(this)) {}
mulNode::mulNode(cgNode* l, cgNode* r) : cgNode(l, r, new mulFunctor, new mulDiffor(this)) {}
divNode::divNode(cgNode* l, cgNode* r) : cgNode(l, r, new divFunctor, new divDiffor(this)) {}
expNode::expNode(cgNode* l, cgNode* r) : cgNode(l, r, new expFunctor, new expDiffor(this)) {}

