#pragma once
#include "Diffor.h"
class lnDiffor :
	public Diffor
{
public:
	lnDiffor(cgNode*);
	~lnDiffor();

	Diffor* clone(cgNode*);
	cgNode* run();
};

