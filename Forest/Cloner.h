#pragma once
#include "cgNode.h"
class Cloner
{
protected:
	Cloner();
	virtual ~Cloner();
public:
	virtual cgNode* operator()(cgNode* node) = 0;
};
