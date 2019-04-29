#pragma once

#include "cgNode.h"
#include <deque>

class cgNode;
class Diffor
{
	friend class cgNode;
private:
protected:
	cgNode* p;
	static std::deque<Diffor*> delq;
	void del_push_self();
public:
	Diffor(cgNode*);
	virtual ~Diffor();
	Diffor* clone(cgNode* pp);
	virtual cgNode* run() { return nullptr; }
	static void clear_delq();
};

#include "addDiffor.h"
#include "subDiffor.h"
#include "mulDiffor.h"
#include "divDiffor.h"
#include "expDiffor.h"