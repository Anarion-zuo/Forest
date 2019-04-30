#pragma once

#include "Functor.h"
#include "Diffor.h"

class Diffor;
class cgNode
{
	friend class addDiffor;
	friend class subDiffor;
	friend class mulDiffor;
	friend class divDiffor;
	friend class cg;
private:
	static cgNode* clone_node(cgNode* node);
protected:
	cgNode* left;
	cgNode* right;
	Functor* func;
	Diffor* diffor;
	double val;
	virtual void trim() {}
public:
	cgNode(cgNode* l, cgNode* r, Functor* f, Diffor* d, const double& v);
	virtual ~cgNode();


	virtual cgNode* clone();
	static bool is_leaf(cgNode*);
	void set_val(const double& d);
	virtual bool is_const();
};

#include "opNode.h"
#include "varNode.h"
#include "constNode.h"