#pragma once

#include "Diffor.h"

class expDiffor : public Diffor
{
public:
	expDiffor(cgNode* pp);
	~expDiffor();

	cgNode* run();
};

