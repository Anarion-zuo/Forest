#pragma once
#include "cgNode.h"
class constNode :
	public cgNode
{
public:
	constNode(const double& v);
	~constNode();

	bool is_const();
	//cgNode* clone();
};

