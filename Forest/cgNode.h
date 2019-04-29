#pragma once

#include "Functor.h"
#include "Diffor.h"

class cgNode
{
	friend class addDiffor;
	friend class subDiffor;
protected:
	cgNode* left;
	cgNode* right;
	Functor* func;
	Diffor* diffor;

public:
	cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d);
	virtual ~cgNode();
};

