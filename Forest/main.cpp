#include "Forest.h"
#include <iostream>

using namespace std;

class A {
public:
	vector<int>* v = new vector<int>;
	A(int a, int b) : v(new vector<int>(a ,b)) {}
	~A() { cout << "~A()" << endl; }
};


int main() {
	varNode* a = new varNode(4), * b = new varNode(3);
	cg p(new addNode(a, b));
	dcg* d = p.diff_graph();
	p.run({ 1,2 });
	auto ddddd = d->single_var(a, { 1,2 });
}