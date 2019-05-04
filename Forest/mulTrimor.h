#pragma once
#include "Trimor.h"
class mulTrimor :
	public Trimor
{
public:
	mulTrimor(cgNode* pp);
	~mulTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

