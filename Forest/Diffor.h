#pragma once

#include "cgNode.h"

class Diffor
{
protected:
	cgNode* p;
public:
	Diffor(cgNode*);
	virtual ~Diffor();

	virtual cgNode* run() = 0;
};
