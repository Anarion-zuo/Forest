#pragma once
#include "Forest.h"

class Trimor
{
protected:
	cgNode* p;
	static bool is_n_node(cgNode* node, const double& n);
public:
	Trimor(cgNode* pp);
	virtual ~Trimor();

	virtual Trimor* clone(cgNode* pp);
	virtual cgNode* run() { return p; }
};

#include "addTrimor.h"
#include "subTrimor.h"
#include "mulTrimor.h"
#include "divTrimor.h"
#include "leafTrimor.h"