#pragma once
#include "Trimor.h"
struct mulTrimor :
	public Trimor
{
public:
	mulTrimor(cgNode* pp);
	~mulTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

