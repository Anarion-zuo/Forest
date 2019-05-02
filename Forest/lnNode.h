#pragma once
#include "cgNode.h"
class lnNode :
	public cgNode
{
public:
	lnNode(cgNode* node);
	~lnNode();

	cgNode* clone();
};

