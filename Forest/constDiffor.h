#pragma once
#include "Diffor.h"
class constDiffor :
	public Diffor
{
public:
	constDiffor(cgNode* pp);
	~constDiffor();

	cgNode* run();
	Diffor* clone(cgNode* node);
};

