#include "Forest.h"
#include <iostream>

using namespace std;

int main() {
	varNode* a = new varNode(5), * b = new varNode(4);
	cg p(new mulNode(new lnNode(a), new constNode(0)));
	dcg* d = p.diff_graph();
	auto ddddd = d->single_var(a, {});
}
