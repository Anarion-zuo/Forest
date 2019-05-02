#pragma once
#include "cgNode.h"

class subNode : public cgNode
{
public:
	subNode(cgNode* l, cgNode* r);
	cgNode* clone();
};