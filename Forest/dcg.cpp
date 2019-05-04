#include "dcg.h"
#include <iostream>



dcg::dcg(cgNode* node, const std::map<cgNode*, varNode*>& m) : cg(node), dvars(m)
{
	varDiffor::clear_map();
	varq.clear();
	refresh_var(root);
}


dcg::~dcg()
{
}

double dcg::single_var(cgNode* node, const std::vector<double>& vallist)
{
	auto it = dvars.find(node);
	if (it == dvars.end())	/*throw "There is no such variable.";*/ std::cout << "There is no such variable." << std::endl;
	else	it->second->set_val(1);
	return compute(root);
}
