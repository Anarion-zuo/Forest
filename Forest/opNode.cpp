#include "opNode.h"
#include "Functor.h"


addNode::addNode(cgNode* l, cgNode* r) : cgNode(l, r, new addFunctor, new addDiffor) {}
subNode::subNode(cgNode* l, cgNode* r) : cgNode(l, r, new subFunctor, new subDiffor) {}
mulNode::mulNode(cgNode* l, cgNode* r) : cgNode(l, r, new mulFunctor, new mulDiffor) {}
divNode::divNode(cgNode* l, cgNode* r) : cgNode(l, r, new divFunctor, new divDiffor) {}
expNode::expNode(cgNode* l, cgNode* r) : cgNode(l, r, new expFunctor, new expDiffor) {}

