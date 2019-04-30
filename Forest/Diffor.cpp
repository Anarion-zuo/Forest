#include "Diffor.h"

std::deque<Diffor*> Diffor::delq;

void Diffor::del_push_self()
{
	delq.push_back(this);
}

Diffor::Diffor(cgNode* pp) : p(pp)
{
}


Diffor::~Diffor()
{
}

Diffor* Diffor::clone(cgNode* pp)
{
	Diffor* res = new Diffor(pp);
	return res;
}

void Diffor::clear_delq()
{
	delq.clear();
}
