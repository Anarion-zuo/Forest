#pragma once
#include "Forest.h"

class Trimor
{
protected:
	cgNode* p;
public:
	Trimor(cgNode* pp);
	virtual ~Trimor();

	virtual Trimor* clone(cgNode* pp);
	virtual cgNode* run() { return p; }
};

