#pragma once
#include "Trimor.h"
class divTrimor :
	public Trimor
{
public:
	divTrimor(cgNode* pp);
	~divTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

