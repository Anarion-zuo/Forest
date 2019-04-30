#include "Forest.h"
#include <iostream>

using namespace std;

int main() {
	varNode* a = new varNode(4), * b = new varNode(3);
	cg p(new addNode(new mulNode(a, a), new mulNode(b, b)));
	dcg* d = p.diff_graph();
	p.run({ 1,6 });
 	auto ddddd = d->single_var(a, { 8,5 });
}