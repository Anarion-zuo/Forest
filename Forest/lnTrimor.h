#pragma once
#include "Trimor.h"
class lnTrimor :
	public Trimor
{
public:
	lnTrimor(cgNode* pp);
	~lnTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

