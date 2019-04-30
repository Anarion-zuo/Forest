#pragma once
#include "Diffor.h"
class divDiffor :
	public Diffor
{
public:
	divDiffor(cgNode* pp);
	~divDiffor();

	cgNode* run();
	Diffor* clone(cgNode* node);
};

