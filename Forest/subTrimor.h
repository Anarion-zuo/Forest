#pragma once
#include "Trimor.h"
class subTrimor :
	public Trimor
{
public:
	subTrimor(cgNode* pp);
	~subTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

