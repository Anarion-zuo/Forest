#pragma once

#include "cgNode.h"
#include <deque>

class cgNode;
class Diffor
{
	friend class cgNode;
	friend class addNode;
	friend class subNode;
	friend class mulNode;
	friend class divNode;
	friend class expNode;
	friend class varNode;
	friend class constNode;
private:
protected:
	cgNode* p;
	static std::deque<Diffor*> delq;
	void del_push_self();
public:
	Diffor(cgNode*);
	virtual ~Diffor();
	virtual cgNode* run() { 
		return p; 
	}
	static void clear_delq();
	virtual Diffor* clone(cgNode* node);
};

#include "addDiffor.h"
#include "subDiffor.h"
#include "mulDiffor.h"
#include "divDiffor.h"
#include "expDiffor.h"
#include "constDiffor.h"
#include "varDiffor.h"