#pragma once
#include "varNode.h"
class dvarNode :
	public varNode
{
public:
	dvarNode(const double& v);
	~dvarNode();
};

