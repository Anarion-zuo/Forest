#include "varNode.h"


varNode::varNode(const double& v = 0) : cgNode(nullptr, nullptr, nullptr, new varDiffor(this), v)
{

}

varNode::~varNode()
{
}
