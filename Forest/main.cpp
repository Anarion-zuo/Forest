#include "AVL_Tree.hpp"
#include "Matrix.h"
#include <iostream>
#include "cg.h"
using namespace std;

class A {
public:
	vector<int>* v = new vector<int>;
	A(int a, int b) : v(new vector<int>(a ,b)) {}
	~A() { cout << "~A()" << endl; }
};


int main() {
	cg p(new addNode(new constNode(3), new constNode(2)));
	auto d = p.diff_graph();
}