#include "constNode.h"



constNode::constNode(const double& v) : cgNode(nullptr, nullptr, nullptr, new constDiffor(this), v)
{

}

constNode::~constNode()
{
}

bool constNode::is_const()
{
	return true;
}

