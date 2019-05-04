#pragma once
#include "Trimor.h"
struct divTrimor :
	public Trimor
{
public:
	divTrimor(cgNode* pp);
	~divTrimor();

	Trimor* clone(cgNode* pp);
	cgNode* run();
};

