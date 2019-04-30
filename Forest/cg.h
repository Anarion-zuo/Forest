#pragma once

#include "cgNode.h"
#include <vector>

class dcg;
class cg
{
private:
	static void del_node(cgNode* node);
	static void diff_node(cgNode*& node);
	static void find_var_node(cgNode* node, std::vector<cgNode*>& qq);
	static double compute(cgNode* node);
protected:
	cgNode* root;
	std::vector<cgNode*> varq;

	void find_vars();
public:
	cg(cgNode* r);
	virtual ~cg();

	cg* clone();
	dcg* diff_graph();
	void diff();
	double run(const std::vector<double>& vallist);
};

#include "dcg.h"