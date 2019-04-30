#pragma once
#include "cg.h"
class dcg :
	public cg
{
public:
	dcg(cgNode*);
	virtual ~dcg();

	double single_var(cgNode* node);
};

