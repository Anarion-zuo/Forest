#pragma once
#include "cgNode.h"

class expNode : public cgNode
{
public:
	expNode(cgNode* l, cgNode* r);
	cgNode* clone();
};