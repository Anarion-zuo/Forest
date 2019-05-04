#include "constNode.h"



constNode::constNode(const double& v) : cgNode(nullptr, nullptr, nullptr, new constDiffor(nullptr), new leafTrimor(nullptr), v)
{
	diffor->p = this;
	trimor->p = this;
}

constNode::~constNode()
{
}

bool constNode::is_const()
{
	return true;
}

//cgNode* constNode::clone()
//{
//	return new constNode(val);
//}

