#pragma once
#include "Diffor.h"
class subDiffor :
	public Diffor
{
public:
	subDiffor(cgNode*);
	virtual ~subDiffor();

	cgNode* run();
	Diffor* clone(cgNode* node);
};

