#include "varNode.h"


varNode::varNode(const double& v = 0) : cgNode(nullptr, nullptr, nullptr, new varDiffor(nullptr), v)
{
	diffor->p = this;
}

varNode::~varNode()
{
}

cgNode* varNode::clone()
{
	return this;
}
