#pragma once

#include "Diffor.h"

class addDiffor : public Diffor
{
public:
	addDiffor(cgNode*);
	~addDiffor();

	cgNode* run() override;
	Diffor* clone(cgNode* node);
};

