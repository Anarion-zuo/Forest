#pragma once

#include "Functor.h"
#include "Diffor.h"

class Diffor;
class cgNode
{
	friend class addDiffor;
	friend class subDiffor;
	friend class mulDiffor;
	friend class cg;
private:
	static cgNode* clone_node(cgNode* node);
protected:
	cgNode* left;
	cgNode* right;
	Functor* func;
	Diffor* diffor;

public:
	cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d);
	virtual ~cgNode();

	cgNode* clone();
};

#include "opNode.h"