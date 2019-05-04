#pragma once
#include "Trimor.h"
class leafTrimor :
	public Trimor
{
public:
	leafTrimor(cgNode* pp);
	~leafTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

