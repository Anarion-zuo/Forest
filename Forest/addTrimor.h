#pragma once
#include "Trimor.h"

struct addTrimor :
	public Trimor
{
	addTrimor(cgNode* pp);
	~addTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

