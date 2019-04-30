#pragma once
#include "Diffor.h"
class varDiffor :
	public Diffor
{
public:
	varDiffor(cgNode* pp);
	~varDiffor();

	cgNode* run();
	Diffor* clone(cgNode* node);
};

