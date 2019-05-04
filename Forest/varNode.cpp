#include "varNode.h"


varNode::varNode(const double& v = 0) : cgNode(nullptr, nullptr, nullptr, new varDiffor(nullptr), new leafTrimor(nullptr), v)
{
	diffor->p = this;
	trimor->p = this;
}

varNode::~varNode()
{
}

cgNode* varNode::clone()
{
	return this;
}
