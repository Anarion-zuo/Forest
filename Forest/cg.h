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
	void trim_node(cgNode* node);
	static double compute(cgNode* node);
	bool is_var(cgNode* node);
protected:
	cgNode* root;
	std::vector<cgNode*> varq;
	void trim();
	void find_vars();
	void refresh_var(cgNode* node);
public:
	cg(cgNode* r);
	virtual ~cg();

	cg* clone();
	dcg* diff_graph();
	void diff();
	double run(const std::vector<double>& vallist);
};

#include "dcg.h"