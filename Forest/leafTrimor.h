#pragma once
#include "Trimor.h"
struct leafTrimor :
	public Trimor
{
public:
	leafTrimor(cgNode* pp);
	~leafTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

