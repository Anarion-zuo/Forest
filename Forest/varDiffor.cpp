#include "varDiffor.h"

std::map<cgNode*, varNode*> varDiffor::dvarmap;

varDiffor::varDiffor(cgNode* pp) : Diffor(pp)
{
}


varDiffor::~varDiffor()
{
}

cgNode* varDiffor::run()
{
	std::map<cgNode*, varNode*>::iterator it = dvarmap.find(p);
	if (it != dvarmap.end()) {
		return it->second;
	}
	varNode* res = new varNode(0);
	push_map(p, res);
	del_push_self();
	return res;
}

Diffor* varDiffor::clone(cgNode* node)
{
	Diffor* res = new varDiffor(node);
	return res;
}

void varDiffor::push_map(cgNode* n, varNode* dn)
{
	dvarmap.insert(std::pair<cgNode*, varNode*>(n, dn));
}

void varDiffor::clear_map()
{
	dvarmap.clear();
}

const std::map<cgNode*, varNode*>& varDiffor::get_map()
{
	return dvarmap;
}

