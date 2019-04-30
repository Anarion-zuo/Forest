#include "dcg.h"



dcg::dcg(cgNode* node, const std::map<cgNode*, varNode*>& m) : cg(node), dvars(m)
{
	varDiffor::clear_map();
}


dcg::~dcg()
{
}

double dcg::single_var(cgNode* node, const std::vector<double>& vallist)
{
	for (size_t i = 0; i < varq.size(); ++i) {
		if (varq[i] != node) {
			dvars.find(node)->second->set_val(0);
		}
		else {
			dvars.find(node)->second->set_val(1);
		}
	}
	return run(vallist);
}
