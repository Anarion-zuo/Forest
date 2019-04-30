#pragma once
#include "cgNode.h"
class varNode :
	public cgNode
{
public:
	varNode(const double& v);
	~varNode();

	cgNode* clone();
};

#include "dvarNode.h"