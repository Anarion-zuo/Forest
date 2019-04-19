#include "AVL_Tree.hpp"
#include "Matrix.h"
#include <iostream>
using namespace std;

class A {
public:
	vector<int>* v = new vector<int>;
	A(int a, int b) : v(new vector<int>(a ,b)) {}
	~A() { cout << "~A()" << endl; }
};


int main() {
	iArray a(9, 9), b(9, 8);
	auto c = a + b;
}