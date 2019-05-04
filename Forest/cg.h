#pragma once

#include "cgNode.h"
#include <vector>

class dcg;
class cgNode;
class cg
{
private:
	static void diff_node(cgNode*& node);
	static void find_var_node(cgNode* node, std::vector<cgNode*>& qq);
	static void trim_node(cgNode*& node);
	bool is_var(cgNode* node);
protected:
	cgNode* root;
	std::vector<cgNode*> varq;
	void find_vars();
	void refresh_var(cgNode* node);
	static double compute(cgNode* node);
public:
	cg(cgNode* r);
	virtual ~cg();

	static void del_node(cgNode* node);
	cg* clone();
	dcg* diff_graph();
	void diff();
	double run(const std::vector<double>& vallist);
};

#include "dcg.h"