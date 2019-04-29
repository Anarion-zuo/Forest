#pragma once
#include "Diffor.h"
class mulDiffor :
	public Diffor
{
public:
	mulDiffor(cgNode*);
	~mulDiffor();

	cgNode* run();
};

