#pragma once

#include "cgNode.h"

class cg
{
private:
	static void del_node(cgNode* node);
	static void diff_node(cgNode*& node);
protected:
	cgNode* root;
public:
	cg(cgNode* r);
	virtual ~cg();

	void diff();
};

