#include "Forest.h"
#include <iostream>

using namespace std;

int main() {
	varNode* a = new varNode(4), * b = new varNode(6);
	cg p(new addNode(new lnNode(a), b));
	dcg* d = p.diff_graph();
	auto ddddd = d->single_var(a, {});
}