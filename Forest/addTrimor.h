#pragma once
#include "Trimor.h"
class addTrimor :
	public Trimor
{
public:
	addTrimor(cgNode* pp);
	~addTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

