#pragma once
#include "Trimor.h"
class expTrimor :
	public Trimor
{
public:
	expTrimor(cgNode* pp);
	~expTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

