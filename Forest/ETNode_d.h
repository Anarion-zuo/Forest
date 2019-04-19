#pragma once

#include "Functor.h"

class ETNode_d
{
private:
	double cnum = 0;
	Functor* f = nullptr;
public:
	ETNode_d(Functor* func, const double& n = 0);
	virtual ~ETNode_d();
};

