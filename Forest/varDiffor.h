#pragma once
#include "Diffor.h"
#include <map>
class dvarNode;
class varDiffor :
	public Diffor
{
private:
	static std::map<cgNode*, varNode*> dvarmap;
public:
	varDiffor(cgNode* pp);
	virtual ~varDiffor();

	cgNode* run();
	Diffor* clone(cgNode* node);
	static void push_map(cgNode* n, varNode* dn);
	static void clear_map();
	static std::map<cgNode*, varNode*>::iterator is_in_map(cgNode* node);
	static const std::map<cgNode*, varNode*>& get_map();
};
