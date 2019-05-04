#pragma once
#include "Forest.h"


struct Trimor
{
	friend class cgNode;
	friend class addNode;
	friend class subNode;
	friend class mulNode;
	friend class divNode;
	friend class expNode;
	friend class constNode;
	friend class varNode;

	static bool equals(const double& n1, const double& n2) {
		return abs(n1 - n2) < 16 * std::numeric_limits<double>::epsilon();
	}

	cgNode* p;
	static bool is_n_node(cgNode* node, const double& n);

	Trimor(cgNode* pp);
	virtual ~Trimor();

	virtual Trimor* clone(cgNode* pp);
	virtual cgNode* run() { return p; }
};

#include "addTrimor.h"
#include "subTrimor.h"
#include "mulTrimor.h"
#include "divTrimor.h"
#include "expTrimor.h"
#include "leafTrimor.h"
#include "lnTrimor.h"