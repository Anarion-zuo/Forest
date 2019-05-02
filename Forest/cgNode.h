#pragma once

#include "Functor.h"
#include "Diffor.h"

class Diffor;
class nullDiffor;
class cgNode
{
	friend class addDiffor;
	friend class subDiffor;
	friend class mulDiffor;
	friend class divDiffor;
	friend class expDiffor;
	friend class lnDiffor;
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



#include "varNode.h"
#include "constNode.h"
#include "addNode.h"
#include "subNode.h"
#include "mulNode.h"
#include "divNode.h"
#include "expNode.h"
#include "lnNode.h"
#include "nullNode.h"
